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
const int N=1e5+5;
const int M=70;
const int SZ=450;
const double eps=1e-9;
const int mod=31607;
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
char s[N];
int a[N];
int x,y,z;
int one;
void put(int k){putchar('a'+k-1);}
bool cmp(int x,int y){return x>y;}
void DOIT()
{
    scanf("%s",s+1);n=strlen(s+1);
    one=0;
    for (int i=1;i<=26;i++) a[i]=0;
    for (int i=1;i<=n;i++) a[s[i]-'a'+1]++;
    for (int i=1;i<=26;i++) if (a[i]==1 && !one) one=i;
    if (one)
    {
        putchar(one+'a'-1);for (int i=1;i<=26;i++) if (i!=one) for (int j=1;j<=a[i];j++) put(i);
        cout<<"\n";
        return;
    }
    int cnt=0;
    for (int i=1;i<=26;i++) if (a[i]) cnt++;
    if (cnt==1)
    {
        for (int i=1;i<=n;i++) cout<<s[i];cout<<"\n";return;
    }
    if (cnt==2)
    {
        for (int i=1;i<=26;i++) if (a[i]) {x=i;break;}
        for (int i=x+1;i<=26;i++) if (a[i]) {y=i;break;}
        if (a[x]>a[y]+2)
        {
            put(x);
            for (int i=1;i<=a[y];i++) put(y);
            for (int i=1;i<a[x];i++) put(x);
            cout<<"\n";return;
        } else 
        {
            put(x);put(x);
            for (int i=1;i<=a[x]-2;i++) put(y),put(x);
            for (int i=a[x]-1;i<=a[y];i++) put(y);
            cout<<"\n";return;
        }
    }
    if (cnt>=3)
    {
        for (int i=1;i<=26;i++) if (a[i]) {x=i;break;}
        for (int i=x+1;i<=26;i++) if (a[i]) {y=i;break;}
        for (int i=y+1;i<=26;i++) if (a[i]) {z=i;break;}
        if (a[x]>n-a[x]+2)
        {
            put(x);put(y);for (int i=1;i<a[x];i++) put(x);
            put(z);a[y]--;a[z]--;
            for (int i=x+1;i<=26;i++) for (int j=1;j<=a[i];j++) put(i);
            cout<<"\n";return;
        } else 
        {
            put(x);put(x);put(y);a[x]-=2;a[y]--;
            while (a[x])
            {
                put(x);while (!a[y]) {y++;if (y>26)break;}if (y<=26)put(y);a[y]--;a[x]--;
            }
            for (int i=x+1;i<=26;i++) for (int j=1;j<=a[i];j++) put(i);
            cout<<"\n";return;
        }
    }

}
signed main()
{
    int JYZ;rd(JYZ);while (JYZ--) 
	DOIT();
}
/*

*/