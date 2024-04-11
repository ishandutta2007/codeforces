#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=14,P=1<<N;

vector<int> dp[P][N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    string s[n];
    for(int i=0;i<n;i++)
        cin>>s[i];
    int p=1<<n;
    for(int mask=1;mask<p;mask++)
        for(int last=0;last<n;last++)
            if((mask>>last)&1)
                dp[mask][last].resize(1<<(__builtin_popcount(mask)-1));
    for(int i=0;i<n;i++)
        dp[1<<i][i][0]=1;
    for(int mask=1;mask<p;mask++)
        for(int last=0;last<n;last++)
            for(int res=0;res<dp[mask][last].size();res++)
                for(int nxt=0;nxt<n;nxt++)
                    if(!((mask>>nxt)&1))
                        dp[mask|(1<<nxt)][nxt][(res<<1)|(s[last][nxt]-'0')]+=dp[mask][last][res];
    for(int res=0;res<(p>>1);res++)
    {
        int ans=0;
        for(int last=0;last<n;last++)
            ans+=dp[p-1][last][res];
        cout<<ans<<" ";
    }
}