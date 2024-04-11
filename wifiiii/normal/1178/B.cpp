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

ll dp[6];
int main()
{
    string s;
    cin>>s;
    ll ans=0;
    fs(i,s)
    {
        if(i>0 && s[i]=='v'&&s[i-1]=='v') dp[3]+=dp[2],dp[1]++;
        else if(s[i]=='o') dp[2]+=dp[1];
    }
    cout<<dp[3]<<endl;
}