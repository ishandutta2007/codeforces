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

vi v[4];

void solve()
{
    int n;scanf("%d",&n);
    if(n<4)puts("-1");
    else
    {
        for(auto i:v[n%4])printf("%d ",i);
        for(int i=4+n%4;i<n;i+=4)
        {
            for(int j=0;j<4;j++)printf("%d ",v[0][j]+i);
        }
        puts("");
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
    v[0]={2,4,1,3};
    v[1]={2,4,1,3,5};
    v[2]={1,4,2,6,3,5};
    v[3]={5,1,3,6,2,4,7};
    int _;cin>>_;
    while(_--)
    {
        solve();
    }
    return 0;
}