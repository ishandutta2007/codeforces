#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define inf 0x3f3f3f3f3f3f3f3f
#define N 205

inline ll cl(ll x,ll y){
	return (x+y-1)/y;
}

ll n,m,k,a[N],b[N],c[N];

ll sa[N],sb[N];

ll f[N][N][2],g[N][N][2];

int main(){
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n;i++)
		scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
	n++;
	a[n]=b[n]=INT_MAX;
	c[n]=inf;
	for(int i=1;i<=n;i++){
		sa[i]=sa[i-1]+a[i];
		sb[i]=sb[i-1]+b[i];
	}
	memset(f,0x3f,sizeof(f));
	memset(g,0x3f,sizeof(g));
	memset(f[0],0,sizeof(f[0]));
	memset(g[0],0,sizeof(g[0]));
	for(int i=1;i<=n;i++)
		for(int j=0;j<=m;j++)
			for(int l=0;l<2;l++){
				if(l*a[i]+j*b[i]<=c[i]&&f[i-1][j][l]<inf){
					f[i][j][l]=std::min(f[i][j][l],f[i-1][j][l]);
					ll L=cl(l*sa[i-1]+j*sb[i-1],k);
					if(L*k<=l*sa[i]+j*sb[i])
						g[i][j][l]=std::min(g[i][j][l],L);
				}
				for(int r=0;r<j;r++)
					if(g[i][r][l]<inf){
						ll rm=l*sa[i]+r*sb[i]-k*g[i][r][l],nd=cl(std::max(rm+(j-r)*b[i]-c[i],0ll),k);
						if(nd*k<=rm&&f[i-1][j-r][0]<inf){
							f[i][j][l]=std::min(f[i][j][l],g[i][r][l]+nd+f[i-1][j-r][0]);
							ll L=cl((j-r)*sb[i-1],k);
							if(L*k<=(j-r)*sb[i]+rm-nd*k)
								g[i][j][l]=std::min(g[i][j][l],g[i][r][l]+nd+L);
						}
					}
			}
	printf("%lld\n",f[n][m][1]);
}