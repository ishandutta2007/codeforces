#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define fe(i,n) for(int i=1;i<=n;++i)
#define ff(i,n) for(int i=0;i<n;++i)
#define fs(i,s) for(int i=0;i<s.size();++i)
#define sz(x) ((int) x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'
const int mod = 1e9+7;

int dp[200005][3];
const string rgb="RGB";
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int q;
    cin>>q;
    while(q--)
    {
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        dp[0][0]=dp[0][1]=dp[0][2]=1;
        for(int i=0;i<s.size();++i)
        {
            for(int j=0;j<3;++j)
            {
                if(s[i] != rgb[(i+j)%3]) dp[i+1][j]=dp[i][j]+1;
                else dp[i+1][j]=dp[i][j];
            }
        }
        int ans=1e9;
        for(int i=1;i+k-1<=s.size();++i)
            for(int j=0;j<3;++j)
                ans=min(ans,dp[i+k-1][j]-dp[i-1][j]);
        cout<<ans<<endl;
    }
}