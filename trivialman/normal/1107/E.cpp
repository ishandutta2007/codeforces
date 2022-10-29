#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
typedef long long LL;
const LL MOD = 998244353;
const int INF = 0x3fffffff;
const int N = 110;

LL dp[N][N][N],a[N],c[N],n,m;
string s;

LL dfs(int l, int r, int more){
	if(l>r)return a[more];
	LL &res=dp[l][r][more];
	if(res)return res;
	res=dfs(l,r-1,0)+a[c[r]+more];
	for(int i=r-2;i>=l;i-=2)res=max(res,dfs(l,i,c[r]+more)+dfs(i+1,r-1,0));
	//printf("%d %d %d %d\n",l,r,more,res);
	return res;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	cin>>n>>s;
	rep(i,1,n)cin>>a[i];
	rep(i,1,n)rep(j,1,i-1)a[i]=max(a[i],a[j]+a[i-j]);
	c[m=1]=1;
	rep(i,2,n) if(s[i-1]==s[i-2]) ++c[m]; else c[++m]=1;
	cout<<dfs(1,m,0)<<endl;
	return 0;
}