#include <bits/stdc++.h>
#define x first
#define y second
#define mid (l + r >> 1)
#define lo (o << 1)
#define ro (lo | 1)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int maxn = 1e5 + 10;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
struct tri{int x,y,z;};

pii arr[maxn];
int n;
pii operator+(pii a,pii b)
{
    return pii({a.x+b.x,a.y+b.y});
}

bool solve()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d%d",&arr[i].x,&arr[i].y);
    arr[n]=arr[0];
    if(n&1)return 0;
    for(int i=0;i<n/2;i++)
    {
        if(arr[i]+arr[i+n/2]!=arr[i+1]+arr[i+n/2+1])return 0;
    }
    return 1;
}
 
int main()
{
    // freopen("in.txt","r",stdin);
    if(solve())puts("yes");
    else puts("no");
    return 0;
}