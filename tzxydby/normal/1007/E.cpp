#include<bits/stdc++.h>
using namespace std;
const int N=205;
const long long inf=0x3f3f3f3f3f3f3f3fll;
int n,t,k,a[N],d[N];
long long sa[N],sd[N],l[N],f[N][N][2],g[N][N][2],v1,v2,v3,v4;
void chmin(long long &x,long long y){if(x>y)x=y;}
int main()
{
	scanf("%d%d%d",&n,&t,&k);
	for(int i=1;i<=n;i++)
		scanf("%d%d%lld",&a[i],&d[i],&l[i]);
	n++,a[n]=d[n]=(1<<30),l[n]=inf;
	for(int i=1;i<=n;i++)
		sa[i]=sa[i-1]+a[i],sd[i]=sd[i-1]+d[i];
	memset(f,inf,sizeof f);
	memset(g,inf,sizeof g);
	memset(f,0,sizeof*f);
	memset(g,0,sizeof*g);
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=t;j++)
		{
			for(int x=0;x<2;x++)
			{
				if(1ll*x*a[i]+1ll*j*d[i]<=l[i]&&f[i-1][j][x]<inf)
				{
					chmin(f[i][j][x],f[i-1][j][x]),v1=(x*sa[i-1]+j*sd[i-1]+k-1)/k;
					if(v1*k<=x*sa[i]+j*sd[i])
						chmin(g[i][j][x],v1);
				}
				for(int r=0;r<j;r++)
				{
					if((v1=g[i][r][x])<inf)
					{
						v3=x*sa[i]+r*sd[i]-k*v1;
						v4=(max(0ll,v3+1ll*d[i]*(j-r)-l[i])+k-1)/k;
						if(v4*k<=v3&&f[i-1][j-r][0]<inf)
						{
							chmin(f[i][j][x],v1+v4+f[i-1][j-r][0]);
							v2=((j-r)*sd[i-1]+k-1)/k;
							if(v2*k<=(j-r)*sd[i]+(v3-v4*k))
								chmin(g[i][j][x],v1+v4+v2);
						}
					}
				}
			}
		}
	}
	printf("%lld\n",f[n][t][1]);
	return 0;
}