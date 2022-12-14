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
    ll ret=0;
    ll x,y,a,b;
    scanf("%lld%lld%lld%lld",&x,&y,&a,&b);
    if(a*2<=b||a*b<=0)
        return (abs(x)+abs(y))*a;
    x=abs(x);y=abs(y);
    if(x>y)swap(x,y);
    return x*b+(y-x)*a;
}

int main()
{
//    freopen("in.txt","r",stdin);
    int _;cin>>_;
    while(_--)
    {
        printf("%lld\n",solve());
    }
    return 0;
}