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

ll arr[maxn],brr[maxn];

ll solve()
{
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%lld%lld",arr+i,brr+i);

    ll ret=max((ll)0,arr[1]-brr[n]);
    for(int i=2;i<=n;i++)ret+=max((ll)0,arr[i]-brr[i-1]);

    ll ma=min(arr[1],brr[n]);
    for(int i=2;i<=n;i++)ma=min(ma,min(arr[i],brr[i-1]));


    return ret+ma;
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