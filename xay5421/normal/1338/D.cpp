#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
template<class T>bool umin(T&x,const T&y){return y<x?x=y,1:0;}
template<class T>bool umax(T&x,const T&y){return x<y?x=y,1:0;}
const int N=100005;
int n,val[N],dp[N][2],ans;
vector<int>e[N];
void dfs(int k1,int k2){
	int son=0;
	for(auto&x:e[k1])if(x!=k2){
		dfs(x,k1);
		++son;
	}
	dp[k1][0]=son,dp[k1][1]=1;
	for(auto&x:e[k1])if(x!=k2){
		umax(ans,dp[k1][0]+max(dp[x][1],dp[x][0])-1+(k2!=0));
		umax(ans,dp[k1][1]+dp[x][0]);
		umax(dp[k1][0],max(dp[x][0],dp[x][1])+son-1);
		umax(dp[k1][1],dp[x][0]+1);
	}
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d",&n);
	rep(i,2,n){
		int k1,k2;
		scanf("%d%d",&k1,&k2);
		e[k1].pb(k2),e[k2].pb(k1);
	}
	dfs(1,0);
	printf("%d\n",ans);
	return 0;
}