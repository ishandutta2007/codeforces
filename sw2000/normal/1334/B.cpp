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
    ll n,x;scanf("%lld%lld",&n,&x);
    for(int i=0;i<n;i++)scanf("%lld",arr+i);
    sort(arr,arr+n,greater<ll>());
    int ret=0;
    if(arr[0]>=x)ret=1;
    for(int i=1;i<n;i++)
    {
        arr[i]+=arr[i-1];
        if((i+1)*x<=arr[i])ret=i+1;
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