#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

const int N=2e5+100,MOD=998244353;

int dp[N][2][2][2][2][2][2];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin>>s;
    int n=s.size();
    s="0"+s;
    dp[0][1][1][1][0][0][0]=1;
    for(int i=1;i<=n;i++)
        for(int pa=0;pa<2;pa++)
        for(int pb=0;pb<2;pb++)
        for(int pc=0;pc<2;pc++)
            for(int da=0;da<2;da++)
            for(int db=0;db<2;db++)
            for(int dc=0;dc<2;dc++)
                for(int ta=0;ta<=(pa?s[i]-'0':1);ta++)
                for(int tb=0;tb<=(pb?s[i]-'0':1);tb++)
                for(int tc=0;tc<=(pc?s[i]-'0':1);tc++)
                    (dp[i]
                       [pa&&ta==s[i]-'0']
                       [pb&&tb==s[i]-'0']
                       [pc&&tc==s[i]-'0']
                       [da||ta!=tb&&ta!=tc]
                       [db||tb!=ta&&tb!=tc]
                       [dc||tc!=ta&&tc!=tb]
                     +=dp[i-1][pa][pb][pc][da][db][dc])%=MOD;
    int ans=0;
    for(int pa=0;pa<2;pa++)
    for(int pb=0;pb<2;pb++)
    for(int pc=0;pc<2;pc++)
        ans+=dp[n][pa][pb][pc][1][1][1];
    cout<<ans%MOD;
}