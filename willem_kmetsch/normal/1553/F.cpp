#include<bits/stdc++.h>
#define endl "\n"
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define rd(x) x=read()
#define write(x) wt(x),putchar(10)
#define pos(x) (((x)-1)/SZ+1)
using namespace std;
const int N=2e5+5;
const int M=6e5+5;
const int SZ=550;
const double eps=1e-9;
const int mod=998244353;
const int inf=0x3f3f3f3f3f3f3f3f;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void wt(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
int inv[N],fac[N],ifc[N]; 
void Init(int n)
{
    inv[1]=1;for (int i=2;i<=n;i++)inv[i]=inv[mod%i]*(mod-mod/i)%mod;
    fac[0]=1;for (int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
    ifc[0]=1;for (int i=1;i<=n;i++) ifc[i]=ifc[i-1]*inv[i]%mod;
}
int C(int n,int m){if (m<0 || m>n) return 0;return fac[n]*ifc[m]%mod*ifc[n-m]%mod;}
void add(int &x,int y) {x+=y;if (x>=mod) x-=mod;}
int n,m,k,ans,mx;
long long sum;
int a[N];
long long p[N];
long long pm[550];
struct treearray
{
    long long a[M];
    int b[M];
    inline void add(int i,int x){for (;i<=mx;i+=i&-i) a[i]+=x,b[i]++;}
    inline long long query(int i){if (i<=0) return 0;long long ret=0;for (;i;i^=i&-i) ret+=a[i];return ret;}
    inline int Query(int i){if (i<=0) return 0;int ret=0;for (;i;i^=i&-i) ret+=b[i];return ret;}
    inline long long operator[](int x) {return query(x);}
}T;
signed main()
{
    rd(n);
    for (int i=1;i<=n;i++) rd(a[i]),m=max(m,a[i]);mx=m*2;
    for (int i=1;i<=n;i++)
    {
        p[i]=p[i-1];
        p[i]+=sum;p[i]+=1ll*a[i]*(i-1);
        for(int l=1,r;l<=a[i];l=r+1)
        {
            r=a[i]/(a[i]/l);
            p[i]-=1ll*(T[r]-T[l-1])*(a[i]/l);
        }
        if (a[i]<SZ) p[i]-=pm[a[i]];else 
        for (int j=1;j<=m/a[i];j++)
        {
            p[i]-=1ll*(T.Query((j+1)*a[i]-1)-T.Query(j*a[i]-1))*j*a[i];
        }
        for (int j=1;j<SZ;j++) pm[j]+=a[i]/j*j;
        T.add(a[i],a[i]);
        sum+=a[i];
    }
    for (int i=1;i<=n;i++) cout<<p[i]<<" ";cout<<endl;
}
/*
1
ababcababcabababc
bcababacba
*/