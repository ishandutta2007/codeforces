#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=998244353;
void ckmx(int &x,int y){x=max(x,y);}
int add(int x,int y){x+=y;return x>=mod?x-mod:x;}
int sub(int x,int y){return add(x,mod-y);}
const int N=500050;
int l[N],r[N],x[N],n,k,m;
int mxl[N],mxr[N],dp[N],top,sum[N];
pair<int,int> stk[N];
bool imp[N];
int cdp[N],ls[N],rs[N],pre[N];
int Solve(){
	for(int i=1;i<=n;i++)mxl[i]=mxr[i]=imp[i]=ls[i]=0;
	for(int i=1;i<=m;i++){
		if(x[i]&1)ckmx(mxl[l[i]],r[i]-l[i]+1);
		else ckmx(mxr[r[i]],l[i]);
	}
	int las=0;
	dp[0]=1;pre[0]=1;
	for(int i=1;i<=n;i++){
		ckmx(mxl[i],mxl[i-1]-1);
		if(mxl[i]>0)dp[i]=0;
		else dp[i]=sub(pre[i-1],(las==0?0:pre[las-1]));
		las=max(las,mxr[i]);
		pre[i]=add(pre[i-1],dp[i]);
	}
	return sub(pre[n],(las==0?0:pre[las-1]));
}
int main(){
	scanf("%i %i %i",&n,&k,&m);
	for(int i=1;i<=m;i++)scanf("%i %i %i",&l[i],&r[i],&x[i]);
	int ans=1;
	for(int i=1;i<=k;i++){
		ans=(ll)ans*Solve()%mod;
		for(int j=1;j<=m;j++)x[j]/=2;
	}
	printf("%i\n",ans);
	return 0;
}