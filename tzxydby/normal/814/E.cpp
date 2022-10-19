#include<bits/stdc++.h>
using namespace std;
const int N=55,mod=1e9+7;
int n,d[N],f[N][N],g[N][N][N];
int y(int i,int j,int k)
{
	if(i<0||j<0)
		return 0;
	int &s=g[i][j][k];
	if(s!=-1)
		return s;
	s=0;
	if(k)
		return (s=(1ll*i*y(i-1,j,k-1)%mod+1ll*j*y(i+1,j-1,k-1)%mod)%mod);
	else if(i)
		return (s=(1ll*(i-1)*y(i-2,j,0)%mod+1ll*j*y(i,j-1,0)%mod)%mod);
	else if(j>2)
	{
		for(int c=3,a=(j-1)*(j-2)/2;c<=j;a=1ll*a*(j-c++)%mod)
			s=(s+1ll*a*y(0,j-c,0)%mod)%mod;
		return s;
	}
	else
		return s=(!j);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&d[i]);
	memset(g,-1,sizeof(g));
	for(int i=n;i>=2;i--)
	{
		int a=(d[i]==2),b=(d[i]==3);
		for(int j=i+1;j<=n+1;j++)
		{
			if(j==n+1)
				f[i][j]=y(a,b,0);
			else
				for(int k=j+1;k<=n+1;k++)
					f[i][j]=(f[i][j]+1ll*y(a,b,k-j)*f[j][k]%mod)%mod;
			a+=(d[j]==2),b+=(d[j]==3);
		}
	}
	printf("%d\n",f[2][2+d[1]]);
	return 0;
}