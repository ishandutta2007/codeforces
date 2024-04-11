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

int n,cnt[1010];
vi edg[1010];

int main()
{
    // freopen("in.txt","r",stdin);
    int n,m;
    scanf("%d%d",&n,&m);
    int sum=0;
    for(int i=3;i<=n;i++)sum+=(i-1)/2;
    if(sum<m)
    {
        puts("-1");
        return 0;
    }
    int i=1;
    for(;m>(i-1)/2;i++)
    {
        printf("%d ",i);
        m-=(i-1)/2;
    }
    if(m)
    {
        printf("%d ",i*2-m*2-1);
        i++;
    }
    for(;i<=n;i++)
    {
        printf("%d ",100000000+i*10000);
    }
    return 0;
}