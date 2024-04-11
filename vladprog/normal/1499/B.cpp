#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=110;

bool dp[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int n=s.size();
        s="0"+s;
        dp[0]=true;
        dp[1]=true;
        for(int i=2;i<=n;i++)
            dp[i]=dp[i-1]&&s[i]>=s[i-1]||
                  dp[i-2]&&s[i]>=s[i-2];
        cout<<(dp[n]||dp[n-1]?"YES\n":"NO\n");
    }
}