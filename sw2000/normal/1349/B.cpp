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

int arr[maxn];
bool solve()
{
    int n,k;scanf("%d%d",&n,&k);
    bool f=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",arr+i);
        if(arr[i]==k)f=1;
    }
    if(!f)return 0;
    if(n==1&&k==arr[1])return 1;
    int now=-1;
    for(int i=1;i<=n;i++)
    {
        if(arr[i]>=k&&now>=0)return 1;
        if(arr[i]>=k)now=max(now+1,1);
        else now--;
    }
    return 0;
}

int main()
{
//    freopen("in.txt","r",stdin);
    int _;cin>>_;
    while(_--)
    {
        if(solve())puts("yes");
        else puts("no");
    }
    return 0;
}