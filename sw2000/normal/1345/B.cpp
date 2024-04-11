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

ll dp[maxn];

int solve()
{
    int ret=0,n;scanf("%d",&n);
    for(int i=100000;i;i--)
    {
        while(n>=dp[i])
        {
            n-=dp[i];
            ret++;
        }
    }
    return ret;
}

int main()
{
//    freopen("out.txt","r",stdin);
    dp[1]=2;
    for(int i=2;i<maxn;i++)
    {
        dp[i]=dp[i-1]+i*2+i-1;
    }
    int _;cin>>_;
    while(_--)
    {
        printf("%d\n",solve());
    }
    return 0;
}