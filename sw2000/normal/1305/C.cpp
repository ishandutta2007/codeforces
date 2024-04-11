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

int arr[maxn],pre[1010][1010];

int main()
{
    // freopen("in.txt","r",stdin);
    int n,m;scanf("%d%d",&n,&m);
    if(n>m)
    {
        puts("0");
        return 0;
    }
    for(int i=0;i<n;i++)scanf("%d",arr+i);
    sort(arr,arr+n);
    ll ans=1;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            ans*=(arr[i]-arr[j])%m;
            ans%=m;
        }
    }
    printf("%d",ans);
    return 0;
}