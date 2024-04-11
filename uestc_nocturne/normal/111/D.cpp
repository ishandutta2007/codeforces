#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
typedef long long LL;
const LL P=1000000007;
const int V=1200;
LL dp[V][V],F[V];
LL Pow(LL x,int y)
{
	LL ret=1;
	LL te=x;
	while(y>0)
	{
		if(y&1)ret=ret*te%P;
		te=te*te%P;y/=2;
	}
	return ret;
}
LL C[V][V];
void init()
{
	int i,j;
	C[1][0]=1;C[1][1]=1;
	for(i=2;i<=1010;i++)
	{
		C[i][0]=1;C[i][i]=1;
		for(j=1;j<i;j++)
		{
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%P;
		}
	}
}
LL Ck[V][V],Ny[V];
LL find(int n,int i,int j,int k)
{
//	printf("Find : %d %d %d %d\n",n,i,j,k);
	return C[i][j]*Ck[i][i-j]%P;
}
int n,m,k,i,j;
int main()
{
	init();
	while(~scanf("%d%d%d",&n,&m,&k))
	{
		for(i=0;i<=n;i++)
		for(j=0;j<=n;j++)
		dp[i][j]=0;
		dp[1][1]=k;
		for(i=2;i<=n;i++)
		{
			for(j=1;j<=i;j++)
			{
				dp[i][j]=dp[i-1][j]*j%P;
				if(j<=k)
				{
					dp[i][j]+=dp[i-1][j-1]*(LL)(k-j+1)%P;
					dp[i][j]%=P;
				}
			}
		}
		LL ans=0;
		if(m==1)
		{
			for(i=1;i<=n;i++)
			{
				ans+=dp[n][i];
				ans%=P;
			}
			cout<<ans<<endl;
			continue;
		}
		else if(m==2)
		{
			for(i=1;i<=n;i++)
			{
				ans+=dp[n][i]*dp[n][i]%P;
				ans%=P;
			}
			cout<<ans<<endl;
			continue;
		}
		int free=n*(m-2);
		F[0]=0;
		for(i=0;i<=n;i++)Ny[i]=Pow(i,(int)P-2);
		for(i=1;i<=n;i++)
		{
			F[i]=Pow(i,free);
		}
		for(j=0;j<=min(k,n);j++)
		{
			Ck[j][0]=1;
			for(i=1;i<=n;i++)
			{
				Ck[j][i]=Ck[j][i-1]*(LL)(k-j-i+1)%P;
				Ck[j][i]*=Ny[i];
				Ck[j][i]%=P;
			}
		}
	//	for(j=0;j<=min(n,k);j++){for(i=1;i<=n;i++)printf("%I64d ",Ck[0][i]);puts("Ck");}
		for(i=1;i<=n;i++)
		{
			dp[n][i]*=Pow(Ck[0][i],(int)P-2);
			dp[n][i]%=P;
		}
	//	for(i=1;i<=n;i++)printf("%I64d ",dp[n][i]);puts("Dp");
		for(i=1;i<=n;i++)
		{
			for(j=0;j<=i;j++)
			{
				ans+=Ck[0][i]*dp[n][i]%P*dp[n][i]%P*find(n,i,j,k)%P*F[j]%P;
				ans%=P;
	//			printf("Cal : %d %d %I64d\n",i,j,ans);
			}
		}
		cout<<ans<<endl;
	}
}