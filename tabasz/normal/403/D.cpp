#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
#define LL long long
const int m=1000000007;
const int M=1001;

LL dp[1001][1001], P[1001][1001], N[2002][2002];
LL sil[1001], pot[2002], W[1001][1001];

LL po(LL x)
{
	LL a=m-2, tmp=1;
	for(int i=29; i>=0; i--)
	{
		tmp=(tmp*tmp)%m;
		if((a>>i)%2==1) tmp=(tmp*x)%m;
	}
	return tmp;
}

int main()
{
	sil[0]=1;
	for(int i=1; i<M; i++) sil[i]=(sil[i-1]*i)%m;
	for(int i=1; i<2*M; i++) pot[i]=po((LL)i);
	dp[0][0]=1;
	P[0][0]=1;
	for(int i=1; i<M; i++) P[i][0]=(P[i-1][0]+dp[i][0])%m;
	for(int j=1; j<M; j++)
	{
		for(int i=1; i<j; i++) P[j][i]=(P[j-1][i]+dp[j][i])%m;
		for(int i=j; i<M; i++)
		{
			dp[j][i]=P[j][i-j];
			P[j][i]=(P[j-1][i]+dp[j][i])%m;
		}
	}
	for(int i=1; i<2*M; i++)
	{
		N[i][i]=1;
		for(int j=i+1; j<2*M; j++)
		{
			LL tmp=(N[j-1][i]*j)%m;
			tmp=(tmp*pot[j-i])%m;
			N[j][i]=tmp;
		}
	}
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n, k;
		scanf("%d%d", &n, &k);
		if(k*(k+1)/2>n)
		{
			printf("0\n");
			continue;
		}
		if(W[k][n])
		{
			printf("%d\n", (int)W[k][n]);
			continue;
		}
		int x=k*(k-1)/2;
		LL w=0;
		for(int i=x+k; i<=n; i++)
		{
			LL tmp=(dp[k][i-x]*N[n-i+k][k])%m;
			w=(w+tmp)%m;
		}
		w=(w*sil[k])%m;
		W[k][n]=w;
		printf("%d\n", (int)w);
	}
	return 0;
}