#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;++i)
#define debug(x) cout<<#x<<":"<<x<<endl;
typedef long long ll;

#define int ll
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef vector<ll> vec2;
typedef vector<vec> mat2;
const int mod = 1e9 + 7;
const int N = 3;
const int N2 = 5;
mat2 mul2(mat2 a,mat2 b)
{
    mat2 c(N2,vec(N2));
    for(int i=0;i<N2;++i)
        for(int j=0;j<N2;++j)
            for(int k=0;k<N2;++k)
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % (mod-1);
    return c;
}
mat2 fpow2(mat2 a,ll n)
{
    mat2 ret(N2,vec2(N2));
    for(int i=0;i<N2;++i) ret[i][i] = 1;
    while(n)
    {
        if(n&1) ret=mul2(ret,a);
        a=mul2(a,a);
        n>>=1;
    }
    return ret;
}
mat mul(mat a,mat b)
{
    mat c(N,vec(N));
    for(int i=0;i<N;++i)
        for(int j=0;j<N;++j)
            for(int k=0;k<N;++k)
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % (mod-1);
    return c;
}
mat fpow(mat a,ll n)
{
    mat ret(N,vec(N));
    for(int i=0;i<N;++i) ret[i][i] = 1;
    while(n)
    {
        if(n&1) ret=mul(ret,a);
        a=mul(a,a);
        n>>=1;
    }
    return ret;
}
ll fpow3(ll a,ll b)
{
    ll ret = 1;
    while(b)
    {
        if(b&1) ret=ret*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ret;
}
int32_t main()
{
    
    mat a(3,vec(3));
    for(int i=0;i<3;++i) for(int j=0;j<3;++j) a[i][j]=0;
    a[0][0]=a[0][1]=a[0][2]=a[1][0]=a[2][1]=1;
    ll n,f1,f2,f3,c;
    cin>>n>>f1>>f2>>f3>>c;
    f1%=mod,f2%=mod,f3%=mod,c%=mod;
    a=fpow(a,n-3);
    mat2 b(5,vec2(5));
    for(int i=0;i<5;++i) for(int j=0;j<5;++j) b[i][j]=0;
    b[0][0]=b[0][1]=b[0][2]=b[0][3]=1;
    b[1][0]=b[2][1]=b[3][3]=b[4][4]=1;
    b[3][4]=2;
    b=fpow2(b,n-3);
    ll ans = fpow3(f1,a[0][2]) % mod * fpow3(f2,a[0][1]) % mod * fpow3(f3,a[0][0]) % mod * fpow3(c,b[0][3]*2+b[0][4]) % mod;
    while(ans>=mod) ans-=mod;
    if(ans<0) ans+=mod;
    cout<<ans<<endl;
}