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
const int N = 1e5 + 10;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
int n,a[300],dp[500][300];
int solve()
{
    cin>>n;
    for(int i=0;i<500;i++)
        for(int j=1;j<=n;j++)
        dp[i][j]=inf;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<400;i++)
    {
        for(int j=1;j<=min(n,i);j++)
        {
            dp[i][j]=min(dp[i-1][j],dp[i-1][j-1]+abs(i-a[j]));
        }
    }
    return dp[399][n];
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
//    freopen("in.txt", "r", stdin);
    int _;cin>>_;
    while(_--)
    {
        cout<<solve()<<endl;
    }
    return 0;
}