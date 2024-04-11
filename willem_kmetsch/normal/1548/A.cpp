#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define rd(x) x=read()
#define write(x) wt(x),putchar(10)
#define pos(x) (((x)-1)/SZ+1)
using namespace std;
const int N=3e5+5;
const int M=6e5+5;
const int SZ=550;
const double eps=1e-9;
const int mod=998244353;
const int inf=0x3f3f3f3f3f3f3f;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void wt(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
int inv[N],fac[N],ifc[N]; 
int V[N];
void Init(int n)
{
    for (int i=2;i<=n;i++) for (int j=i*i;j<=n;j+=i) V[j]=1;
}
int C(int n,int m){if (m<0 || m>n) return 0;return fac[n]*ifc[m]%mod*ifc[n-m]%mod;}
void add(int &x,int y) {x+=y;if (x>=mod) x-=mod;}
int n,q,m,k,ans;
int a[N],b[N];
void DOIT()
{
    rd(n);rd(m);ans=n;
    for (int i=1;i<=m;i++) 
    {
        int u,v;rd(u);rd(v);
        if (u>v) swap(u,v);
        a[u]++;if (a[u]==1) ans--;
    }
    rd(q);
    while (q--)
    {
        int op,u,v;
        rd(op);if (op!=3) rd(u),rd(v);if (u>v) swap(u,v);
        if (op==1) {a[u]++;if (a[u]==1) ans--;}
        if (op==2) {a[u]--;if (a[u]==0) ans++;}
        if (op==3) {cout<<ans<<"\n";}
    }

}
signed main()
{
    //int JYZ;rd(JYZ);while (JYZ--)
    DOIT();
}
/*
1
ababcababcabababc
bcababacba
*/