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
const int maxn = 3e5 + 10;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
struct tri{int x,y,z;};

ll n,l,r;

void solve()
{
    scanf("%lld%lld%lld",&n,&l,&r);
    ll base=0;
    for(ll i=2*(n-1);i;base+=i,i-=2)
    {
        for(ll j=max(base+1,l);j<=min(base+i,r);j++)
        {
            ll a;
            if(j%2)a=n-i/2;
            else a=(j-base)/2+n-i/2;
            printf("%lld ",a);
        }
    }
    if(base==r-1)printf("1");
}

int main()
{
//    freopen("in.txt","r",stdin);
    int _;cin>>_;
    while(_--)
    {
        solve();
        puts("");
    }

    return 0;
}