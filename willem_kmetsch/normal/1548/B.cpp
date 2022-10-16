#include<bits/stdc++.h>
#define int long long
#define ls (rt<<1)
#define rs (rt<<1|1)
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
const int inf=0x3f3f3f3f3f3f3f;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void wt(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
int n,q,m,k,ans;
int a[N],b[N],p[N];
struct SegT
{
    int l,r,w;
}T[N*4];

void pushup(int rt){T[rt].w=__gcd(T[ls].w,T[rs].w);}
int Sum(int rt,int L,int R)
{
    int ans=0;
    if (L<=T[rt].l && T[rt].r<=R) return T[rt].w;
    int mid=(T[rt].l+T[rt].r)>>1;
    if (L<=mid) ans=__gcd(ans,Sum(ls,L,R));
    if (R>mid) ans=__gcd(ans,Sum(rs,L,R));
    return ans;
}
void build(int rt,int L,int R)
{
    T[rt].l=L;
    T[rt].r=R;
    T[rt].w=0;
    if (L==R){T[rt].w=b[L];return;}
    int mid=(L+R)>>1;
    build(ls,L,mid);
    build(rs,mid+1,R);
    pushup(rt);
}

void DOIT()
{
    rd(n);
    for (int i=1;i<=n;i++) rd(a[i]);
    if (n==1) {puts("1");return;}
    for (int i=1;i<n;i++) b[i]=llabs(a[i+1]-a[i]);
    build(1,1,n-1);
    int l=1;
    for (int i=1;i<n;i++)
    {
        while (Sum(1,l,i)==1) {l++;if (l==i+1) break;}
        p[i]=l;
    }
    int mx=0;
    //for (int i=1;i<n;i++) cout<<p[i]<<" ";cout<<endl;
    for (int i=1;i<n;i++) mx=max(mx,i-p[i]+2);
    cout<<mx<<endl;

}
signed main()
{
    int JYZ;rd(JYZ);while (JYZ--)
    DOIT();
}
/*
*/