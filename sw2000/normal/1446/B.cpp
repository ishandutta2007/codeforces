#include<bits/stdc++.h>
#define fi first
#define se second
#define mid (l+r>>1)
#define endl '\n'
using namespace std;
typedef long long ll;
typedef pair<int, int>pii;
typedef vector<int>vi;
struct tri {int a, b, c;};
const int N = 2e5 + 10;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;

int n,m;
string a,b;
int dp[N];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
//    freopen("in.txt", "r", stdin);
    cin>>n>>m>>a>>b;
    a=" "+a;
    b=" "+b;
    int ans=0;
    for(int i=1;i<=m;i++)
    {
        for(int j=n;j;j--)
        {
            if(b[i]==a[j])
            {
                dp[j]=dp[j-1]+2;
            }
            else dp[j]=max(0,dp[j]-1);
            ans=max(ans,dp[j]);
        }
        for(int j=1;j<=n;j++)
            dp[j]=max(dp[j],dp[j-1]-1);
    }
    cout<<ans;
    return 0;
}