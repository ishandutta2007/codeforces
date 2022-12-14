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
const int maxn = 4e5 + 10;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
struct tri{int x,y,z;};

int arr[maxn],c[maxn],cnt[maxn];
int solve()
{
    int ret=inf;
    int n,k;scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%d",arr+i);
    for(int i=1;i<=n/2;i++)
    {
        if(arr[i]>arr[n-i+1])
            swap(arr[i],arr[n-i+1]);
        c[arr[i]+1]++;
        c[arr[n-i+1]+k+1]--;
        cnt[arr[i]+arr[n-i+1]]++;
    }
    for(int i=1;i<=k*2;i++)c[i]+=c[i-1];

    for(int i=2;i<=k*2;i++)
    {
//        cout<<cnt[i]<<" "<<c[i]<<endl;
        ret=min(ret,n-cnt[i]-c[i]);
    }
    for(int i=0;i<=k*2+2;i++)
    {
        c[i]=cnt[i]=0;
    }

    return ret;
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