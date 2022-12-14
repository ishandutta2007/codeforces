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

ll arr[maxn];
map<ll,int>m;

int main()
{
//    freopen("in.txt","r",stdin);
    int n,st=-1;scanf("%d",&n);
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        int a;scanf("%d",&a);
        arr[i]=arr[i-1]+a;
        if(m[arr[i]])st=max(st,m[arr[i]]);
        else if(arr[i]==0)st=0;
        ans+=i-st-1;
        m[arr[i]]=i;
    }
    printf("%lld",ans);
    return 0;
}