#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int maxn=1e5+10;
const int inf=0x3f3f3f3f;
const ll mod=1e9+7;
const ll linf=0x3f3f3f3f3f3f3f3f;

ll n,k;

ll solve()
{
    ll ret=0;
    ll a=9;
    while(a<=k)
    {
        ret+=(ll)n;
        a*=10;
        a+=9;
    }
    return ret;
}

int main()
{
//    freopen("in.txt","r",stdin);
    int _;
    cin>>_;
    while(_--)
    {
        cin>>n>>k;
        printf("%lld\n",solve());
    }
    return 0;
}