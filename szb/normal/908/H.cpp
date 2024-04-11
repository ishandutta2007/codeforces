#include<bits/stdc++.h>
using namespace std;
#define E long long
#define P(i,x,y) for(E i=x;i<y;++i)
#define O(i,x,y) for(E i=x;i<=y;++i)
#define h(x) return cout<<x<<endl,0
const E N=60;char s[N];E fa[N],sz[N],a[N][N],L[N],n,Z,f[1<<23],g[1<<23];E F(E x){return x==fa[x]?x:fa[x]=F(fa[x]);}int main(){cin>>n;O(i,1,n)fa[i]=i,sz[i]=1;O(i,1,n){cin>>s+1;O(j,1,n)if(s[j]=='A')fa[F(i)]=F(j),sz[fa[j]]+=sz[fa[i]];else if (s[j]=='X')a[i][j]=1;}O(i,1,n)L[i]=L[F(i)]=sz[fa[i]]>1?(L[fa[i]]?L[fa[i]]:++Z):0;O(i,1,n)O(j,1,n)if ((i^j)&&L[i]&&L[j]&&(i^j)&&a[i][j])if (L[i]^L[j])f[(1<<L[i]-1)^(1<<L[j]-1)]=1;else h(-1);E U=1<<Z;P(i,0,U)P(j,0,Z)if(i>>j&1)f[i]|=f[i^(1<<j)];P(i,0,U)f[i]=!f[i],g[i]=1;if (!Z)h(n-1);for(E d=1;d<U;d<<=1)for(E i=0;i<U;i+=d<<1)for(E j=0;j<d;++j)f[i+j+d]=f[i+j]+f[i+j+d];P(A,1,n){E now=0;P(i,0,U)g[i]*=f[i],now+=(__builtin_popcount((1<<Z)-1^i)&1)?g[i]:-g[i];if(now)h(n+A-1);}}