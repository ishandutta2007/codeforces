#include<bits/stdc++.h>
using namespace std;
int N,M,T;
const int max_T=2e3+5;
int X[max_T],Y[max_T];
struct Point
{
	int x,y;
}p[max_T];
inline bool operator < (const Point &a,const Point &b)
{
	return a.x!=b.x?a.x<b.x:a.y<b.y;
}
const int max_R=2e5+5;
int fac[max_R],inv[max_R],inv_fac[max_R];
const int mod=1e9+7;
inline int C(int n,int m)
{
    if(n<0||m<0||n<m)
        return 0;
    return 1ll*fac[n]*inv_fac[m]%mod*inv_fac[n-m]%mod;
}
int f[max_T];
int main()
{
	scanf("%d%d%d",&N,&M,&T);
    --N,--M;
	for(int i=1;i<=T;++i)
    {
		scanf("%d%d",&p[i].x,&p[i].y);
        --p[i].x,--p[i].y;
    }
	sort(p+1,p+T+1);
	for(int i=1;i<=T;++i)
		X[i]=p[i].x,Y[i]=p[i].y;
	X[++T]=N,Y[T]=M;
    fac[0]=inv_fac[0]=1;
    fac[1]=inv[1]=inv_fac[1]=1;
    for(int i=2;i<=N+M;++i)
    {
        fac[i]=1ll*fac[i-1]*i%mod;
        inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
        inv_fac[i]=1ll*inv_fac[i-1]*inv[i]%mod;
    }
    for(int i=1;i<=T;++i)
    {
        f[i]=C(X[i]+Y[i],Y[i]);
        for(int j=1;j<i;++j)
        {
            if(X[j]<=X[i]&&Y[j]<=Y[i])
            {
                f[i]=(f[i]-1ll*C(X[i]-X[j]+(Y[i]-Y[j]),Y[i]-Y[j])*f[j])%mod;
                f[i]+=f[i]<0?mod:0;
            }
        }
    }
    printf("%d\n",f[T]);
	return 0;
}