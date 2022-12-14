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

int arr[maxn];

int solve()
{
    bool vis[maxn]={0};
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",arr+i);
    for(int i=0;i<n;i++)
    {
        arr[i]=(arr[i]%n+n+i)%n;
        vis[arr[i]]=1;
    }
    for(int i=0;i<n;i++)if(!vis[i])return 0;
    return 1;
}

int main()
{
//    freopen("in.txt","r",stdin);
    int _;cin>>_;
    while(_--)
    {
        if(solve())puts("YES");
        else puts("NO");
    }
    return 0;
}