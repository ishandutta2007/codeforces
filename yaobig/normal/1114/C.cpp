#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 1000000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef vector<int> vi;
typedef double db;

vector<pli> p;
ll ans=1ll<<60;

void solve(ll n,ll x,int k)
{
    ll cnt=0;
    while(n) n/=x,cnt+=n;
    ans=min(ans,cnt/k);
}

int main()
{
    ll n,b; scanf("%I64d%I64d",&n,&b);
    for(ll i=2;i*i<=b;i++)
    {
        if(b%i==0)
        {
            int cnt=0;
            while(b%i==0) b/=i,cnt++;
            p.pb(mp(i,cnt));
        }
    }
    if(b>1) p.pb(mp(b,1));
    for(auto it: p) solve(n,it.FI,it.SE);
    printf("%I64d\n",ans);
    return 0;
}