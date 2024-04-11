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

ll arr[maxn],brr[maxn];

int solve()
{
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%lld",arr+i);

    ll ma=arr[1],mx=-linf;
    for(int i=2;i<=n;i++)
    {
        ma=max(ma,arr[i]);
        mx=max(mx,ma-arr[i]);
    }

    ll sum=0;
    int ret=0;
    while(sum<mx)
    {
        sum+=(ll)1<<ret;
        ret++;
    }
    return ret;
}

int main()
{
//    freopen("in.txt","r",stdin);
    int _;cin>>_;
    while(_--)
    {
        printf("%d\n",solve());
    }

    return 0;
}