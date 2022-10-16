#include<bits/stdc++.h>
#define int long long
#define endl "\n"
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define rd(x) x=read()
#define write(x) wt(x),putchar(10)
#define pos(x) (((x)-1)/SZ+1)
#define mx2 adjkfhakhdjksf
using namespace std;
const int N=1e6+5;
const int M=70;
const int SZ=450;
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
int n,m,k,ans;
int a[N],b[N];
char s[N],t[N];
int mx1,mn1,mn2,mx2;
void DOIT()
{
    mx1=mn1=mx2=mn2=0;
    scanf("%s",s+1);
    for (int i=1;i<=10;i++)
    {
        if (i%2==1)
        {
            if (mx1>(mn2+(10-i+1)/2)) {cout<<i-1<<endl;return;}
            if (s[i]=='1') mx1++,mn1++;
            if (s[i]=='?') mx1++;
            if (mx1>(mn2+(10-i+1)/2)) {cout<<i<<endl;return;}
        } else 
        {
            if (mx2>(mn1+(10-i+1)/2)) {cout<<i-1<<endl;return;}
            if (s[i]=='1') mx2++,mn2++;
            if (s[i]=='?') mx2++;
            if (mx2>(mn1+(10-i+1)/2)) {cout<<i<<endl;return;}
        }
    }
    cout<<10<<endl;

}
signed main()
{
    Init(N-1);
    int JYZ;rd(JYZ);while (JYZ--)
    DOIT();
}