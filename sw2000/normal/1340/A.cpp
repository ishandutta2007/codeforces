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

int arr[maxn],pos[maxn],c[maxn];
bool solve()
{
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",arr+i);
        pos[arr[i]]=i;
    }
    bool vis[maxn]={0};
    bool f=0;
    vis[n+1]=1;
    for(int i=1;i<=n;i++)
    {
        vis[pos[i]]=1;
        if(f==0)
        {
            if(vis[pos[i]+1]==0)f=1;
        }
        else
        {
            if(vis[pos[i]-1]==0)return 0;
            else if(vis[pos[i]+1])f=0;
        }
    }

    return 1;
}

int main()
{
//    freopen("in.txt","r",stdin);
    int _;cin>>_;
    while(_--)
    {
        if(solve())puts("Yes");
        else puts("No");
    }
    return 0;
}