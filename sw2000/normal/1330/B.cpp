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

bool is(int arr[],int l)
{
    bool vis[maxn]={0};
    for(int i=0;i<l;i++)
    {
        if(vis[arr[i]]||arr[i]>l)return 0;
        else vis[arr[i]]=1;
    }
    return 1;
}

void solve()
{
    int arr[maxn],cnt[maxn]={0};
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",arr+i);
        cnt[arr[i]]++;
    }
    int l,r;
    for(int i=1;i<n;i++)
    {
        if(cnt[i]<cnt[i+1]||cnt[i]>=3)
        {
            puts("0");
            return;
        }
        if(cnt[i]==2&&cnt[i+1]<2)
        {
            l=i;
            r=n-i;
        }
    }
    vector<pii>v;
    if(is(arr,l))v.push_back({l,r});
    if(l!=r&&is(arr,r))v.push_back({r,l});
    printf("%d\n",v.size());
    for(auto i:v)printf("%d %d\n",i.x,i.y);
}

int main()
{
    int _;cin>>_;
    while(_--)
    {
        solve();
    }
    return 0;
}