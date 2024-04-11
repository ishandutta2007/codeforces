#include<bits/stdc++.h>
using namespace std;
const int max_n=50+5;
int l[max_n],r[max_n],L[max_n],R[max_n];
const int max_m=1e5+5;
int dp[max_n][max_m],pre[max_n][max_m],f[max_m];
const int mod=998244353;
inline void add(int &a,int b)
{
	a=a+b-(a+b>=mod?mod:0);
}
inline void sub(int &a,int b)
{
	a=a-b+(a<b?mod:0);
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%d%d",l+i,r+i);
	for(int d=1;d<=m;++d)
	{
		bool flag_break=false;
		int sL=0;
		for(int i=1;i<=n;++i)
		{
			L[i]=(l[i]+d-1)/d;
			R[i]=r[i]/d;
			if(L[i]>R[i])
			{
				flag_break=true;
				break;
			}
			sL+=L[i];
		}
		if(flag_break)
			continue;
		int M=m/d;
		if(M<sL)
			continue;
		dp[0][0]=1;
		for(int i=0;i<=M;++i)
			pre[0][i]=1;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=M;++j)
			{
				int l=j-R[i],r=j-L[i];
				if(r>=0)
					dp[i][j]=pre[i-1][r];
				if(l>=1)
					sub(dp[i][j],pre[i-1][l-1]);
				pre[i][j]=pre[i][j-1];
				add(pre[i][j],dp[i][j]);
			}
		f[d]=pre[n][M];
	}
	for(int i=m;i>=1;--i)
		for(int j=i<<1;j<=m;j+=i)
			sub(f[i],f[j]);
	printf("%d\n",f[1]);
	return 0;
}