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

int main()
{
//    freopen("out.txt","r",stdin);
    int _;cin>>_;
    while(_--)
    {
        int n,m;scanf("%d%d",&n,&m);
        if(n>m)swap(n,m);
        if(n==1||n==2&&m==2)puts("YES");
        else puts("NO");
    }
    return 0;
}