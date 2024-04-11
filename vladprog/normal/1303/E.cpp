#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

int dp[410][410];
#define upd(x,y) x=max(x,y)

bool solve(string s,string t)
{
    int s_size=s.size();
    int t_size=t.size();
    s+='#';
    t+='$';
    for(int i=0;i<=t_size;i++)
    {
        memset(dp,255,sizeof(dp));
        dp[0][0]=i;
        for(int j=0;j<=s_size;j++)
            for(int k=0;k<=i;k++)
            {
                if(dp[j][k]==-1)
                    continue;
                upd(dp[j+1][k],dp[j][k]);
                if(s[j]==t[k])
                    upd(dp[j+1][k+1],dp[j][k]);
                if(s[j]==t[dp[j][k]])
                    upd(dp[j+1][k],dp[j][k]+1);
            }
        if(dp[s_size][i]==t_size)
            return true;
    }
    return false;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        string s,t;
        cin>>s>>t;
        cout<<(solve(s,t)?"YES\n":"NO\n");
    }
}