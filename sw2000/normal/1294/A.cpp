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
const int maxn = 1e4 + 10;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
struct tri{int x,y,z;};

bool solve()
{
    int a[4];
    for(int i=0;i<4;i++)scanf("%d",a+i);
    int sum=0;
    for(int i=0;i<4;i++)sum+=a[i];
    if(sum%3)return 0;
    for(int i=0;i<3;i++)
    {
        if(a[i]>sum/3)return 0;
    }
    return 1;
}

int main()
{
    // freopen("in.txt","r",stdin);
    int t;
    cin>>t;
    while(t--)
    {
        if(solve())puts("YES");
        else puts("NO");

    }
    return 0;
}