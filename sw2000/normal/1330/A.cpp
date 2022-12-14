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
const int maxn = 3e3 + 10;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
struct tri{int x,y,z;};

int solve()
{
    int n,x,vis[210]={0};
    scanf("%d%d",&n,&x);
    for(int i=0;i<n;i++)
    {
        int a;scanf("%d",&a);
        vis[a]=1;
    }
    for(int i=1;;i++)
    {
        if(!vis[i])
        {
            if(x)x--;
            else return i-1;
        }
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
    int _;cin>>_;
    while(_--)
    {
        printf("%d\n",solve());
    }
    return 0;
}