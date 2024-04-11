#include <bits/stdc++.h>
#define fi first
#define se second
#define mid (l+r>>1)
#define lo (o<<1)
#define ro (o<<1|1)
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int, int>pii;
struct tri {int a, b, c;};
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int N = 1e5 + 10;
const ll mod = 1e9 + 7;
const double PI = acos(0) * 2;
int r,n,dp[N],ma[N];
tri a[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
//    freopen("in.txt", "r", stdin);
    cin>>r>>n;
    a[0]={0,1,1};
    for(int i=1;i<=n;i++)
    {
        dp[i]=-inf;
        cin>>a[i].a>>a[i].b>>a[i].c;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i-1;~j;j--)
        {
            int t=a[i].a-a[j].a;
            if(t>r*2)
            {
                dp[i]=max(dp[i],ma[j]+1);
                break;
            }
            int dis=abs(a[j].b-a[i].b)+abs(a[j].c-a[i].c);
            if(dis<=t)dp[i]=max(dp[i],dp[j]+1);
        }
        ma[i]=max(dp[i],ma[i-1]);
//        cout<<dp[i]<<endl;
    }
    cout<<ma[n];
    return 0;
}