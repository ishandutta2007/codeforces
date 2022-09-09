#include <bits/stdc++.h>
using namespace std;
const int N=100050;
const int L=17;
const int M=1<<L;
bool bad[M],tmp[M],dp[M];
int a[N],mat[L][L],cnt[L];
char s[N];
int main()
{
	int n,p,i,j,k;
	scanf("%i %i",&n,&p);
	scanf("%s",s+1);
	for(i=1;i<=n;i++) a[i]=s[i]-'a',cnt[a[i]]++;
	for(i=0;i<p;i++) for(j=0;j<p;j++)
	{
		scanf("%i",&mat[i][j]);
		if(mat[i][j]) continue;
		for(int mask=0;mask<(1<<p);mask++) tmp[mask]=0;
		k=1;
		for(;k<=n && a[k]!=i && a[k]!=j;k++);
		for(;k<=n;)
		{
			int t=k;
			int mask=0;
			for(k++;k<=n && a[k]!=i && a[k]!=j;k++) mask|=1<<a[k];
			if(k<=n && ((a[k]==i && a[t]==j) || (a[k]==j && a[t]==i))) tmp[mask]=1;
		}
		for(int mask=0;mask<(1<<p);mask++)
		{
			if(((mask>>i)&1) || ((mask>>j)&1)) continue;
			for(k=0;k<p;k++) if((mask>>k)&1) tmp[mask]|=tmp[mask^(1<<k)];
			bad[mask]|=tmp[mask];
		}
	}
	int ans=0;
	dp[0]=1;
	for(int mask=1;mask<(1<<p);mask++)
	{
		if(bad[mask]) continue;
		int tmp=0;
		for(k=0;k<p;k++) if((mask>>k)&1) dp[mask]|=dp[mask^(1<<k)],tmp+=cnt[k];
		if(dp[mask]) ans=max(ans,tmp);
	}
	printf("%i\n",n-ans);
	return 0;
}