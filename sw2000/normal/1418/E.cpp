#include <bits/stdc++.h>
#define x first
#define y second
#define mid (l+r>>1)
#define lo (o<<1)
#define ro (o<<1|1)
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int,int>pii;
struct tri{int x,y,z;};
const int inf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int N=2e5+10;
const ll mod=998244353;
const double PI=acos(0)*2;
ll qm(ll a,ll b)
{
    ll ret=1;
    for(;b;a=a*a%mod,b>>=1)
        if(b&1)ret=ret*a%mod;
    return ret;
}
ll pre[N],n,m,arr[N];
ll solve()
{
    ll cnt,v;cin>>cnt>>v;
    ll p=lower_bound(arr+1,arr+1+n,v)-arr;
    ll a=p-1;
    ll b=n-a;
    if(b<cnt)return 0;

    ll pa=pre[a]*qm(a,mod-2)%mod;
    ll pb=(pre[n]-pre[a]+mod)*qm(b,mod-2)%mod;
    ll ret=(b-cnt+1)*a%mod*qm(b+1,mod-2)%mod*pa%mod;

    ret=(ret+(b-cnt)*pb)%mod;
    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
//    freopen("in.txt","r",stdin);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>arr[i];
    sort(arr+1,arr+1+n);
    for(int i=1;i<=n;i++)pre[i]=(arr[i]+pre[i-1])%mod;
    while(m--)
    {
        cout<<solve()<<endl;
    }
    return 0;
}