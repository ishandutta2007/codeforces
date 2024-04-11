#include<bits/stdc++.h>
#define int long long
#define endl "\n"
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define rd(x) x=read()
#define write(x) wt(x),putchar(10)
#define pos(x) (((x)-1)/SZ+1)
using namespace std;
const int N=1e6+5;
const int M=70;
const int SZ=450;
const double eps=1e-9;
const int mod=1e9+7;
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
int n,m,k,ans,l,r;
void add(int &x,int y) {x+=y;if (x>=mod) x-=mod;}
char c[N];
int s[N],a[N],b[N],sa[N],sb[N],as,bs;
bool cmp(int x,int y){return x>y;}
void DOIT()
{
    rd(n);
    for (int i=1;i<=n;i++) rd(a[i]);
    for (int i=1;i<=n;i++) rd(b[i]);
    sort(b+1,b+n+1,cmp);
    sort(a+1,a+n+1,cmp);
    for (int i=1;i<=n;i++) sa[i]=sa[i-1]+a[i];
    for (int i=1;i<=n;i++) sb[i]=sb[i-1]+b[i];
    as=sa[n-n/4],bs=sb[n-n/4];
    int t=0;while (as<bs)
    {
        t++;
        bs=sb[min((n+t)-(n+t)/4,n)];
        as=100*t+sa[(n+t)-(n+t)/4-t];
    }
    cout<<t<<endl;

}
signed main()
{
    int JYZ;rd(JYZ);while (JYZ--) 
	DOIT();
}
/*
*/