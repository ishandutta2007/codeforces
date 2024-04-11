#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long LL;
const int N=300005;
int n,pre[3][N];
LL a[2][N];
map<LL,int>t[3];
map<pair<int,int>,int>ans;
int sol(int n,int m){
	if(pre[0][n]==-1&&pre[1][m]==-1&&pre[2][min(n,m)]==-1)return 0;
	if(ans.count({n,m}))return ans[{n,m}];
	int&res=ans[{n,m}];
	if(pre[0][n]>pre[1][m])assert(pre[0][n]!=-1),res=max(res,sol(pre[0][n],m)+1);
	else if(pre[1][m]!=-1)res=max(res,sol(n,pre[1][m])+1);
	if(pre[2][min(n,m)]!=-1)res=max(res,sol(pre[2][min(n,m)],pre[2][min(n,m)])+1);
	return res;
}
int main(){
	memset(pre,-1,sizeof(pre));
	scanf("%d",&n);
	rep(i,0,1)rep(j,1,n)scanf("%lld",&a[i][j]),a[i][j]+=a[i][j-1];
	t[0][0]=t[1][0]=t[2][0]=0;
	rep(i,1,n){
		if(t[0].count(a[0][i]))pre[0][i]=t[0][a[0][i]];
		if(t[1].count(a[1][i]))pre[1][i]=t[1][a[1][i]];
		if(t[2].count(a[0][i]+a[1][i]))pre[2][i]=t[2][a[0][i]+a[1][i]];
		t[0][a[0][i]]=t[1][a[1][i]]=t[2][a[0][i]+a[1][i]]=i;
		rep(j,0,2)pre[j][i]=max(pre[j][i],pre[j][i-1]);
	}
	printf("%d\n",sol(n,n));
	return 0;
}