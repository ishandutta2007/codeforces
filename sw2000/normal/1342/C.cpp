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

int a,b,q,l;

ll f(ll o)
{
    ll ret=o+1-o/l*b-min((ll)b,o%l+1);
    return ret;
}

int main()
{
//    freopen("in.txt","r",stdin);
    int _;cin>>_;
    while(_--)
    {
        scanf("%d%d%d",&a,&b,&q);
        if(a>b)swap(a,b);
        l=a*b/__gcd(a,b);
        while(q--)
        {
            ll l,r;scanf("%lld%lld",&l,&r);
            printf("%lld ",f(r)-f(l-1));
        }
        puts("");
    }

    return 0;
}