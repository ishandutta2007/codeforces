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

ll walk[4]={0,2,3,1};

ll solve()
{
    ll n;scanf("%lld",&n);
    ll base=1,id;
    while(1)
    {
        if(base*4>n)break;
        base*=4;
    }
    n-=base;
    id=n/3;

    ll ret[3];
    ret[0]=base+id;
    ret[1]=base*2;

    for(ll i=0;id;i+=2,id>>=2)
    {
        ret[1]+=walk[id%4]<<i;
    }
    ret[2]=ret[0]^ret[1];
//    for(int i=0;i<3;i++)cout<<ret[i]<<' ';cout<<endl;
    return ret[n%3];
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