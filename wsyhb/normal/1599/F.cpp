#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
inline int qpow(int a,int n)
{
	int res=1;
	while(n>0)
	{
		if(n&1)
			res=1ll*res*a%mod;
		a=1ll*a*a%mod;
		n>>=1;
	}
	return res;
}
int N,Q;
const int max_N=2e5+5;
int A[max_N];
const int K=100;
const int max_K=K+5;
int C[max_K][max_K],S[max_K][max_N],sum[max_N],sum_Kth[max_N],Pow[max_N][max_K];
inline void init()
{
	for(int i=0;i<=K;++i)
	{
		C[i][0]=1;
		for(int j=1;j<=i;++j)
		{
			C[i][j]=C[i-1][j]+C[i-1][j-1];
			C[i][j]-=C[i][j]>=mod?mod:0;
		}
	}
	for(int i=1;i<=N-1;++i)
	{
		Pow[i][0]=1;
		for(int j=1;j<=K;++j)
			Pow[i][j]=1ll*Pow[i][j-1]*i%mod;
	}
	for(int i=0;i<=K;++i)
	{
		S[i][0]=i?0:1;
		for(int j=1;j<N;++j)
		{
			S[i][j]=S[i][j-1]+Pow[j][i];
			S[i][j]-=S[i][j]>=mod?mod:0;
		}
	}
	for(int i=1;i<=N;++i)
	{
		sum[i]=sum[i-1]+A[i];
		sum[i]-=sum[i]>=mod?mod:0;
		sum_Kth[i]=sum_Kth[i-1]+qpow(A[i],K);
		sum_Kth[i]-=sum_Kth[i]>=mod?mod:0;
	}
}
int main()
{
	scanf("%d%d",&N,&Q);
	for(int i=1;i<=N;++i)
		scanf("%d",A+i);
	init();
	while(Q--)
	{
		int L,R,D;
		scanf("%d%d%d",&L,&R,&D);
		int n=R-L+1,d=D;
		int A0=((sum[R]-sum[L-1])-n*(n-1ll)/2%mod*d)%mod*qpow(n,mod-2)%mod;
		A0+=A0<0?mod:0;
//		fprintf(stderr,"A0=%d\n",A0);
		int goal=0;
		if(A0)
		{
			int x=1ll*d*qpow(A0,mod-2)%mod;
			int Pow=1;
			for(int j=0;j<=K;++j)
			{
				goal=(goal+1ll*C[K][j]*Pow%mod*S[j][n-1])%mod;
				Pow=1ll*Pow*x%mod;
			}
			goal=1ll*goal*qpow(A0,K)%mod;
//			fprintf(stderr,"%d\n",sum_Kth[R]-sum_Kth[L-1]);
//			fprintf(stderr,"goal=%d\n",goal);
		}
		else
			goal=1ll*S[K][n-1]*qpow(d,K)%mod;
		puts((sum_Kth[R]-sum_Kth[L-1]-goal)%mod?"No":"Yes");
	}
	return 0;
}