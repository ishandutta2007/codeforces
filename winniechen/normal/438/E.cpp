#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 100005
#define ll long long
#define mod 998244353
int q_pow(int x,int n){int ret=1;for(;n;n>>=1,x=(ll)x*x%mod)if(n&1)ret=(ll)ret*x%mod;return ret;}
#define inv(x) q_pow(x,mod-2)
int A[N<<2],B[N<<2],tmp[N],tx[N],ty[N],Q,n,m;
void NTT(int *a,int len,int flag)
{
    int i,j,k,t,w,x,tmp;
    for(i=k=0;i<len;i++)
    {
        if(i>k)swap(a[i],a[k]);
        for(j=len>>1;(k^=j)<j;j>>=1);
    }
    for(k=2;k<=len;k<<=1)
    {
        t=k>>1;x=q_pow(3,(mod-1)/k);if(flag==-1)x=inv(x);
        for(i=0;i<len;i+=k)
            for(w=1,j=i;j<i+t;j++)
            {
                tmp=(ll)a[j+t]*w%mod;
                a[j+t]=(a[j]-tmp+mod)%mod;a[j]=(a[j]+tmp)%mod;
                w=(ll)w*x%mod;
            }
    }if(flag==-1)for(t=inv(len),i=0;i<len;i++)a[i]=(ll)t*a[i]%mod;
}
struct poly
{
    vector<int>a;int len;
    poly(){}
    poly(int x){len=1;a.push_back(x);}
    void clear(){len=0;a.clear();}
    void rev(){reverse(a.begin(),a.end());}
    void resize(int x){a.resize(x);len=x;}
    poly operator + (const poly &b) const
    {
        poly c;c.len=max(len,b.len);c.resize(c.len);
        for(int i=0;i<len;i++)c.a[i]=a[i];
        for(int i=0;i<b.len;i++)c.a[i]=(c.a[i]+b.a[i])%mod;
        return c;
    }
    poly operator - (const poly &b) const
    {
        poly c;c.len=max(len,b.len);c.resize(c.len);
        for(int i=0;i<len;i++)c.a[i]=a[i];
        for(int i=0;i<b.len;i++)c.a[i]=(c.a[i]-b.a[i]+mod)%mod;
        return c;
    }
    poly operator * (const poly &b) const
    {
        poly c;c.len=len+b.len;
        int n=1;while(n<c.len)n<<=1;
        for(int i=0;i<len;i++)A[i]=a[i];for(int i=len;i<n;i++)A[i]=0;
        for(int i=0;i<b.len;i++)B[i]=b.a[i];for(int i=b.len;i<n;i++)B[i]=0;
        NTT(A,n,1);NTT(B,n,1);for(int i=0;i<n;i++)A[i]=(ll)A[i]*B[i]%mod;NTT(A,n,-1);
        for(int i=0;i<c.len;i++)c.a.push_back(A[i]);
        return c;
    }
    poly operator + (const int &b) const {poly c;c.len=len;c.a=a;(c.a[0]+=b)%=mod;return c;}
    poly operator * (const int &b) const {poly c;c.len=len;for(int i=0;i<len;i++)c.a.push_back((ll)a[i]*b%mod);return c;}
    void get_inv(poly &b,int n)
    {
        if(n==1){b.a.push_back(inv(a[0]));b.len=1;return ;}
        get_inv(b,n>>1);int t=n<<1;int lim=min(len,n);
        for(int i=0;i<lim;i++)A[i]=a[i];for(int i=lim;i<t;i++)A[i]=0;
        for(int i=0;i<b.len;i++)B[i]=b.a[i];for(int i=b.len;i<t;i++)B[i]=0;
        NTT(A,t,1);NTT(B,t,1);for(int i=0;i<t;i++)A[i]=(2-(ll)A[i]*B[i]%mod+mod)*B[i]%mod;NTT(A,t,-1);
        for(int i=0;i<b.len;i++)b.a[i]=A[i];for(int i=b.len;i<n;i++)b.a.push_back(A[i]);b.len=n;
    }
    poly Dao(){poly c;c.len=len-1;for(int i=0;i<c.len;i++)c.a.push_back(a[i+1]*(i+1ll)%mod);return c;}
    poly Jifen(){poly c;c.len=len+1;c.a.push_back(0);for(int i=0;i<len;i++)c.a.push_back((ll)a[i]*inv(i+1)%mod);return c;}
    poly get_ln(int len)
    {
        poly b=Dao();poly c;get_inv(c,len);
        return (b*c).Jifen();
    }
    void get_mod(int b){for(int i=b;i<len;i++)a.pop_back();len=b;}
    int get_val(int x)
    {
        int ret=a[0];
        for(int i=1,tmp=x;i<len;tmp=(ll)tmp*x%mod,i++)ret=(ret+(ll)a[i]*tmp)%mod;
        return ret;
    }
    poly operator / (poly b)
    {
        rev();b.rev();poly c;
        int n=1;while(n<(len-b.len+1))n<<=1;
        b.get_inv(c,n);c.get_mod(len-b.len+1);
        n=1;while(n<len+c.len)n<<=1;
        for(int i=0;i<len;i++)A[i]=a[i];for(int i=len;i<n;i++)A[i]=0;
        for(int i=0;i<c.len;i++)B[i]=c.a[i];for(int i=c.len;i<n;i++)B[i]=0;
        NTT(A,n,1);NTT(B,n,1);for(int i=0;i<n;i++)A[i]=(ll)A[i]*B[i]%mod;NTT(A,n,-1);
        for(int i=0;i<c.len;i++)c.a[i]=A[i];c.rev();rev();b.rev();
        return c;
    }
    poly operator % (poly b)
    {
        rev();b.rev();poly c;
        int n=1;while(n<(len-b.len+1))n<<=1;
        b.get_inv(c,n);c.get_mod(len-b.len+1);
        n=1;while(n<len+c.len)n<<=1;
        for(int i=0;i<len;i++)A[i]=a[i];for(int i=len;i<n;i++)A[i]=0;
        for(int i=0;i<c.len;i++)B[i]=c.a[i];for(int i=c.len;i<n;i++)B[i]=0;
        NTT(A,n,1);NTT(B,n,1);for(int i=0;i<n;i++)A[i]=(ll)A[i]*B[i]%mod;NTT(A,n,-1);
        for(int i=0;i<c.len;i++)c.a[i]=A[i];c.rev();rev();b.rev();
        for(int i=0;i<c.len;i++)A[i]=c.a[i];for(int i=c.len;i<n;i++)A[i]=0;
        for(int i=0;i<b.len;i++)B[i]=b.a[i];for(int i=b.len;i<n;i++)B[i]=0;
        NTT(A,n,1);NTT(B,n,1);for(int i=0;i<n;i++)A[i]=(ll)A[i]*B[i]%mod;NTT(A,n,-1);
        c.len=b.len;c.resize(c.len);for(int i=0;i<c.len;i++)c.a[i]=(a[i]-A[i]+mod)%mod;
        return c;
    }
}a,b;
void get_rot(const poly &a,poly &b,int len)
{
    if(len==1){b.a.push_back(1);b.len=1;return ;}
    get_rot(a,b,len>>1);poly c;c.clear();b.get_inv(c,len);int t=len<<1;
    for(int i=0;i<len;i++)A[i]=a.a[i],B[i]=c.a[i];for(int i=len;i<t;i++)A[i]=B[i]=0;
    NTT(A,t,1);NTT(B,t,1);for(int i=0;i<t;i++)A[i]=(ll)A[i]*B[i]%mod;NTT(A,t,-1);
    for(int i=0;i<b.len;i++)b.a[i]=(b.a[i]+A[i])%mod;
    for(int i=b.len;i<len;i++)b.a.push_back(A[i]);b.len=len;
    b=b*((mod+1)>>1);
    // printf("%d %d\n",b.len,len);
    // for(int i=0;i<len;i++)printf("%d ",b.a[i]);puts("");
}
void get_exp(const poly &a,poly &b,int len)
{
    if(len==1){b.a.push_back(1);b.len=1;return ;}get_exp(a,b,len>>1);
    b=b*((a-b.get_ln(len))+1);b.get_mod(len);
}
// void build(int l,int r,int rt)
// {
// 	f[rt].clear();
// 	if(l==r){f[rt].a.push_back(mod-tmp[l]);f[rt].a.push_back(1);f[rt].len=2;return ;}
// 	int m=(l+r)>>1;build(l,m,rt<<1);build(m+1,r,rt<<1|1);f[rt]=f[rt<<1]*f[rt<<1|1];f[rt].get_mod(r-l+2);
// }
// void get_val(poly F,int l,int r,int rt,int *ret)
// {
// 	if(l==r){ret[l]=F.get_val(l);return ;}int m=(l+r)>>1;
// 	// printf("%d %d\n",l,r);
// 	get_val(F%f[rt<<1],l,m,rt<<1,ret);
// 	get_val(F%f[rt<<1|1],m+1,r,rt<<1|1,ret);
// }
// pair<poly ,poly > solve(int l,int r)
// {
// 	if(l==r){poly a=poly(tmp[l]),b=poly(mod-tx[l]);b.a.push_back(1);b.len++;return make_pair(a,b);}
// 	int m=(l+r)>>1;pair<poly ,poly > L=solve(l,m);pair<poly ,poly > R=solve(m+1,r);
// 	return make_pair(L.first*R.second+R.first*L.second,L.second*R.second);
// }
int main()
{
    scanf("%d%d",&n,&m);int len=1;while(len<=m)len<<=1;a.resize(len);a.a[0]=1;
    for(int i=1,x;i<=n;i++)
    {
        scanf("%d",&x);
        if(x<=m)a.a[x]=mod-4;
    }
    get_rot(a,b,len);
    // for(int i=0;i<len;i++)printf("%d ",b.a[i]);puts("");
    b.a[0]++;a.clear();b.get_inv(a,len);
    for(int i=1;i<=m;i++)printf("%d\n",(a.a[i]<<1)%mod);
}