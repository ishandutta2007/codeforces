#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M=10000050;
const int N=250050;
ll w[M];
int h[M],lid[N],len[N],C[N],d[N];
int stk[M],c,q[M],ql,rng[M];
ll dp[M][2];
int main()
{
	int n,m,i,j;
	scanf("%i %i",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%i",&len[i]);
		for(j=lid[i];j<lid[i]+len[i];j++) scanf("%i",&d[j]);
		for(j=lid[i];j<lid[i]+len[i];j++) scanf("%i",&C[j]);
		lid[i+1]=lid[i]+len[i];
	}
	int qu,id,mul,cnt=0;
	scanf("%i",&qu);
	for(;qu--;)
	{
		scanf("%i %i",&id,&mul);
		for(i=lid[id];i<lid[id]+len[id];i++)
		{
			cnt++;
			h[cnt]=d[i];
			w[cnt]=(ll)C[i]*mul;
			//printf("(%i %lld)\n",h[cnt],w[cnt]);
		}
		//printf(":D\n");
	}
	for(i=1;i<=m;i++)
	{
		while(c && i-h[i]<stk[c]) c--;
		int l=stk[c]+1;
		stk[++c]=i;
		dp[i][0]=min(dp[l-1][0],dp[l-1][1])+w[i];
		dp[i][1]=min(dp[i-1][0],dp[i-1][1])+w[i];
		while(ql && rng[q[ql]]<=i) ql--;
		rng[i]=i+h[i];
		if(ql) dp[i][1]=min(dp[i][1],dp[q[ql]][1]);
		while(ql && rng[q[ql]]<=rng[i]) ql--;
		if(!ql || dp[i][1]<dp[q[ql]][1]) q[++ql]=i;
		//printf("%i %lld\n",h[i],w[i]);
		//printf("l:%i h:%i w:%lld (%lld %lld)\n",l,h[i],w[i],dp[i][0],dp[i][1]);
	}
	printf("%lld\n",min(dp[m][0],dp[m][1]));
	return 0;
}