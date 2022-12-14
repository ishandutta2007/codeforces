#include <bits/stdc++.h>
#define x first
#define y second
#define mid (l + r >> 1)
#define lo (o << 1)
#define ro (lo | 1)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int maxn = 2e5 + 10;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
struct tri{int x,y,z;};

ll n,k,jie[maxn],ni[maxn];
ll qm(ll a,ll b)
{
    ll ret=1;
    while(b)
    {
        if(b&1)ret=ret*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ret;
}
ll C(ll a,ll b)
{
    return jie[a]*ni[a-b]%mod*ni[b]%mod;
}
int main()
{
//    freopen("in.txt","r",stdin);
    scanf("%lld%lld",&n,&k);
    if(k>=n)
    {
        puts("0");
        return 0;
    }
    jie[0]=1;
    for(int i=1;i<=n;i++)jie[i]=jie[i-1]*i%mod;
    ni[n]=qm(jie[n],mod-2);
    for(int i=n-1;~i;i--)ni[i]=ni[i+1]*(i+1)%mod;

    if(k==0)
    {
        printf("%d",jie[n]);
        return 0;
    }

    ll ans=0;
    for(int i=0;i<n-k;i++)
    {
        ans+=(i&1?-1:1)*C(n-k,i)%mod*qm(n-k-i,n)%mod;
        ans=(ans+mod)%mod;
    }
    ans=ans*2*C(n,n-k)%mod;
    cout<<ans<<endl;

    return 0;
}