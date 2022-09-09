#include <stdio.h>
const int N=1005;
const int mod=1e9+7;
int sum[N][26];
int Get(int l, int r, int j){ return sum[r][j]-sum[l-1][j];}
bool good[N][N],was1[N][N],was2[N][N];
int dp1[N][N],dp2[N][N];
int DP1(int l, int r)
{
	if(l>r) return 1;
	if(was1[l][r]) return dp1[l][r];
	was1[l][r]=1;
	for(int i=l;i<=r;i++)
	{
		dp1[l][r]+=good[l][i]*DP1(i+1,r);
		if(dp1[l][r]>=mod) dp1[l][r]-=mod;
	}
	return dp1[l][r];
}
int min(int a, int b){ return a>b?b:a;}
int DP2(int l, int r)
{
	if(l>r) return 0;
	if(was2[l][r]) return dp2[l][r];
	was2[l][r]=1;
	dp2[l][r]=mod;
	for(int i=l;i<=r;i++)
	{
		if(good[l][i]) dp2[l][r]=min(dp2[l][r],1+DP2(i+1,r));
	}
	return dp2[l][r];
}
char s[N];
int cnt[26],sol;
int max(int a, int b){ return a>b?a:b;}
int main()
{
	int n,i,j,k;
	scanf("%i",&n);
	scanf("%s",s+1);
	for(i=1;i<=n;i++)
	{
		for(j=0;j<26;j++) sum[i][j]=sum[i-1][j];
		sum[i][s[i]-'a']++;
	}
	for(i=0;i<26;i++) scanf("%i",&cnt[i]);
	for(i=1;i<=n;i++) for(j=i;j<=n;j++)
	{
		good[i][j]=1;
		for(k=0;k<26;k++)
		{
			if(Get(i,j,k))
			{
				if(cnt[k]<j-i+1) good[i][j]=0;
			}
		}
		if(good[i][j]) sol=max(sol,j-i+1);
	}
	printf("%i\n%i\n%i\n",DP1(1,n),sol,DP2(1,n));
	return 0;
}