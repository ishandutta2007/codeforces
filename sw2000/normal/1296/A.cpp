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

bool solve()
{
    int n;scanf("%d",&n);
    int sum=0;
    bool f1=0,f2=0;
    for(int i=0;i<n;i++)
    {
        int a;scanf("%d",&a);
        if(a&1)f1=1;
        else f2=1;
        sum+=a;
    }
    if(sum&1)return 1;
    if(f1&&f2)return 1;
    return 0;
}
 
int main()
{
    // freopen("in.txt","r",stdin);
    int _;cin>>_;
    while(_--)
    {
        if(solve())puts("YES");
        else puts("NO");
    }
    return 0;
}