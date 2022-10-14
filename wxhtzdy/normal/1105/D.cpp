#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
const int N=1050;
const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};
int n,m,p,a[10];
int ans[10],nxt[10];
char s[N][N];
deque<pii> que[10];
bool ok;
bool Valid(int i,int j){return 1<=i&&i<=n&&1<=j&&j<=m&&s[i][j]=='.';}
int main(){
	scanf("%i%i%i",&n,&m,&p);
	for(int i=1;i<=p;i++)scanf("%i",&a[i]);
	for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if('0'<=s[i][j]&&s[i][j]<='9'){
				que[s[i][j]-'0'].push_back({i*N+j,0});
			}
		}
	}
	for(int rep=1;;rep++){
		ok=false;
		for(int i=1;i<=p;i++){
			while(!que[i].empty()){
				int x=que[i][0].first/N;
				int y=que[i][0].first%N;
				int d=que[i][0].second;
				if(d>=rep*a[i])break;
				for(int dir=0;dir<4;dir++){
					int nx=x+dx[dir],ny=y+dy[dir];
					if(Valid(nx,ny)){
						ok=true;
						que[i].push_back({nx*N+ny,d+1});
						s[nx][ny]=(char)('0'+i);
					}
				}
				que[i].pop_front();
			}
		}
		if(!ok)break;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if('0'<=s[i][j]&&s[i][j]<='9')ans[s[i][j]-'0']++;
		}
	}
	for(int i=1;i<=p;i++)printf("%i ",ans[i]);
	return 0;
}