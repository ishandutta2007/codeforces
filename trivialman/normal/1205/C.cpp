#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define MP make_pair
#define PB push_back
#define PII pair<int, int>
typedef long long LL;
const LL P = 998244353;
const int N = 51;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,a[N][N],b[N][N],dp1[N][N][N][N],dp2[N][N][N][N];

int ask(int x,int y,int i,int j,int type){
	cout<<"? "<<x<<" "<<y<<" "<<i<<" "<<j<<endl<<flush;
	int z;
	cin>>z;
	if(type==1){
		a[x][y] = z==1 ? a[i][j] : 1 - a[i][j];
	}else if(type==2){
		a[i][j] = z==1 ? a[x][y] : 1 - a[x][y];
	}
	return z;
}

int dfs(int a[N][N],int dp[N][N][N][N],int x1,int y1,int x2,int y2){
	if(x1==x2 && y1==y2) return 1;
	if(x2+y2==x1+y1+1) return a[x1][y1]==a[x2][y2];
	int &res = dp[x1][y1][x2][y2];
	if(res>=0)return res;
	if(a[x1][y1]!=a[x2][y2]) return res = 0;
	
	res = 0;
	if(x1+2<=x2 && dfs(a,dp,x1+1,y1,x2-1,y2)) res = 1;
	if(y1+2<=y2 && dfs(a,dp,x1,y1+1,x2,y2-1)) res = 1;
	if(x1+1<=x2 && y1+1<=y2 && (dfs(a,dp,x1+1,y1,x2,y2-1) || dfs(a,dp,x1,y1+1,x2-1,y2)) ) res = 1;
	//printf("%d %d %d %d %d\n",x1,y1,x2,y2,res);
	return res;
}

int main(){
	//freopen("test.in","r",stdin);
	cin>>n;
	a[1][1] = a[1][2] = 1;
	a[n][n] = 0;
	ask(1,2,3,2,2);
	ask(2,1,3,2,1);
	rep(i,1,n)rep(j,1,n){
		if(i+j<=3 || i==n && j==n || i==3 && j==2)continue;
		int x,y;
		if(i==1) x=i, y=j-2;
		else if(j==1) x=i-2, y=1;
		else x=i-1, y=j-1;
		ask(x,y,i,j,2);
	}
	
	memcpy(b,a,sizeof b);
	rep(i,1,n)rep(j,1,n) if((i+j)%2) b[i][j] = 1 - b[i][j];
	/*rep(i,1,n){
		rep(j,1,n)cout<<a[i][j];
		cout<<endl;
	}cout<<endl;
	rep(i,1,n){
		rep(j,1,n)cout<<b[i][j];
		cout<<endl;
	}cout<<endl;*/
	
	memset(dp1,-1,sizeof dp1);
	memset(dp2,-1,sizeof dp2);
	rep(x1,1,n)rep(y1,1,n)rep(x2,x1,n)rep(y2,y1,n)if(x2+y2-2>=x1+y1 && (x2+y2-x1-y1)%2){
		if(dp1[x1][y1][x2][y2]==-1) dfs(a,dp1,x1,y1,x2,y2);
		if(dp2[x1][y1][x2][y2]==-1) dfs(b,dp2,x1,y1,x2,y2);
		//printf("%d %d %d %d %d %d\n",x1,y1,x2,y2,dp1[x1][y1][x2][y2],dp2[x1][y1][x2][y2]);
		if(dp1[x1][y1][x2][y2]!=dp2[x1][y1][x2][y2]){
			if(ask(x1,y1,x2,y2,0)!=dp1[x1][y1][x2][y2]) memcpy(a,b,sizeof a);
			
			cout<<"!\n";
			rep(i,1,n){
				rep(j,1,n)cout<<a[i][j];
				cout<<endl;
			}
			return 0;
		}
	}
	
	return 0;
}