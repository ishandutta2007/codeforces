#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
#define mt make_tuple
#define ldb double
#define pii pair<int,int>
#define pll pair<ll,ll>
template<typename T>void ckmn(T &a,T b){a=min(a,b);}
template<typename T>void ckmx(T &a,T b){a=max(a,b);}
int ri(){int x;scanf("%i",&x);return x;}
void rd(){}
template<typename...T>void rd(int &x,T&...args){scanf("%i",&x);rd(args...);}
template<typename...T>void rd(ll &x,T&...args){scanf("%lld",&x);rd(args...);}
template<typename...T>void rd(ldb &x,T&...args){scanf("%lf",&x);rd(args...);}
template<typename...T>void rd(pii &x,T&...args){scanf("%i %i",&x.first,&x.second);rd(args...);}
const int N=55;
char base[N][N];
int mv[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int main(){
	for(int t=ri();t--;){
		int n,m;rd(n,m);
		for(int i=1;i<=n;i++)scanf("%s",base[i]+1);
		bool ok=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(base[i][j]=='B'){
					for(int k=0;k<4;k++){
						int x=i+mv[k][0];
						int y=j+mv[k][1];
						if(base[x][y]=='.')base[x][y]='#';
						else if(base[x][y]=='G')ok=0;
					}
				}
			}
		}
		queue<int> q;vector<vector<bool>> was(n+2,vector<bool>(m+2,false));
		if(base[n][m]!='#')q.push(n*N+m),was[n][m]=1;
		while(q.size()){
			int i=q.front()/N;
			int j=q.front()%N;
			q.pop();
			for(int k=0;k<4;k++){
				int x=i+mv[k][0];
				int y=j+mv[k][1];
				if(x>=1&&x<=n&&y>=1&&y<=m&&base[x][y]!='#'&&!was[x][y]){
					was[x][y]=1;
					q.push(x*N+y);
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(base[i][j]=='G'&&!was[i][j])ok=0;
				if(base[i][j]=='B'&&was[i][j])ok=0;
			}
		}
		if(ok)printf("Yes\n");
		else printf("No\n");
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)base[i][j]=0;
	}
	return 0;
}