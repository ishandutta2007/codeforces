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

int n;
ll arr[maxn],pre[maxn],la[maxn],ans;

int main()
{
//    freopen("in.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",arr+i);
    }

    ans=arr[1];
    for(int i=2;i<=n;i++)ans=__gcd(ans,arr[i]);
    for(int i=1;i<=n;i++)arr[i]/=ans;
    pre[1]=arr[1];la[n]=arr[n];
    for(int i=2;i<=n;i++)pre[i]=__gcd(pre[i-1],arr[i]);
    for(int i=n-1;i;i--)la[i]=__gcd(la[i+1],arr[i]);
    ans*=pre[n-1]*la[2];
    for(int i=2;i<n;i++)ans*=__gcd(pre[i-1],la[i+1]);
    printf("%lld",ans);
    return 0;
}