#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define CL(a,x) memset(a, x, sizeof(a))
#define MP make_pair
#define PB push_back
#define PII pair<int, int>
typedef long long LL;
const LL P = 998244353;
const int N = 1005;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,m,p;
int a[N][N],b[15],ans[15];
char s[N];
struct dat{
	int x,y,t;
};
queue<dat> q[10], q1[10];
int dx[] = {-1,0,0,1};
int dy[] = {0,-1,1,0};

int main(){
	//freopen("test.in","r",stdin);
	cin>>n>>m>>p;
	rep(i,1,p)cin>>b[i];
	
	rep(i,0,n+1)rep(j,0,m+1) a[i][j]=10;
	rep(i,1,n){
		cin>>(s+1);
		rep(j,1,m){
			if(s[j]=='.')a[i][j]=0;
			else if(s[j]=='#')a[i][j]=10;
			else a[i][j] = s[j]-48, q[a[i][j]].push({i,j,0});
		}
	}
	while(true){
		rep(i,1,p){
			while(!q[i].empty()){
				dat x = q[i].front();
				q[i].pop();
				//cout<<i<<" "<<x.x<<" "<<x.y<<" "<<x.t<<endl;
				if(x.t==b[i]) break;
				
				rep(k,0,3){
					int x1 = x.x+dx[k], y1 = x.y+dy[k];
					if(!a[x1][y1]){
						a[x1][y1] = i;
						q[i].push({x1,y1,x.t+1});
						q1[i].push({x1,y1,x.t+1});
					}
				}
			}
		}
		bool flag = false;
		rep(i,1,p) if(!q1[i].empty()) flag = true;
		if(!flag) break;
		
		rep(i,1,p){
			while(!q[i].empty()) q[i].pop();
			while(!q1[i].empty()){
				dat x = q1[i].front();
				q[i].push({x.x,x.y,0});
				q1[i].pop();
			}
		}
	}
	rep(i,1,n)rep(j,1,m){
		++ans[a[i][j]];
		//cout<<a[i][j]<<" ";
		//if(j==m) cout<<endl;
	}
	rep(i,1,p)cout<<ans[i]<<" ";cout<<endl;
	return 0;
}