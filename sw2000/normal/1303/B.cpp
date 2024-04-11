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
const int maxn = 1e5 + 10;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
struct tri{int x,y,z;};

ll solve()
{
    ll n,a,b;scanf("%lld%lld%lld",&n,&a,&b);
    if(a>=b)return n;

    ll left;
    left=n/(a+b)*a;
    left+=min(a,n%(a+b));
    if(left*2>=n)return n;

    n=(n+1)/2;
    if(n%a)return n/a*(a+b)+n%a;
    else return n/a*(a+b)-b;
}

int main()
{
    // freopen("in.txt","r",stdin);
    int _;cin>>_;
    while(_--)
    {
        printf("%lld\n",solve());
    }
    return 0;
}