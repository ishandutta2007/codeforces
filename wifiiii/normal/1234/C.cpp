#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i )
#define sz(x) ((int) x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

int dp[200005][2];
int main()
{
    int q;
    cin>>q;
    while(q--)
    {
        int n;
        cin>>n;
        ii dp[i][0]=dp[i][1]=0;
        string s1,s2;
        cin>>s1>>s2;
        for(int i=0;i<n;++i) if(s1[i]=='1' || s1[i]=='2') s1[i]='2';else s1[i]='3';
        for(int i=0;i<n;++i) if(s2[i]=='1' || s2[i]=='2') s2[i]='2';else s2[i]='3';
        dp[0][0] = 1;
        for(int i=1;i<=n;++i)
        {
            if(s1[i-1] == '2' && dp[i-1][0]) dp[i][0] = 1;
            if(s2[i-1] == '2' && dp[i-1][1]) dp[i][1] = 1;
            if(s2[i-1] == '3' && s1[i-1] == '3' && dp[i-1][0]) dp[i][1] = 1;
            if(s1[i-1] == '3' && s2[i-1] == '3' && dp[i-1][1]) dp[i][0] = 1;
        }
        if(dp[n][1]) cout<<"YES\n";
        else cout<<"NO\n";
    }
}