#include <bits/stdc++.h>
#define x first
#define y second
#define mid (l + r >> 1)
#define lo (o << 1)
#define ro (lo | 1)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef vector<int> vi;
const int maxn = 3500 + 10;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
struct tri{int x,y,z;};

int n,m,k;
int arr[maxn];

int solve()
{
    if(m<=k)
    {
        int ma=0;
        for(int i=1;i<=m;i++)ma=max(ma,arr[i]);
        for(int i=1;i<=m;i++)ma=max(ma,arr[n-i+1]);
        return ma;
    }

    int ret=0;
    int len=n-m;
    int brr[maxn]={0};
    for(int i=1;i<=m;i++)
    {
        brr[i]=max(arr[i],arr[i+len]);
    }
    for(int i=1;i<=k+1;i++)
    {
        int mi=inf;
        for(int j=0;j<m-k;j++)
        {
            mi=min(mi,brr[i+j]);
        }
        ret=max(mi,ret);
    }
    return ret;
}

int main()
{
    // freopen("in.txt","r",stdin);
    int t;cin>>t;
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&k);
        for(int i=1;i<=n;i++)scanf("%d",arr+i);
        printf("%d\n",solve());
    }

    return 0;
}