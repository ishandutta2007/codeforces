#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=998244353;
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s;cin>>s;reverse(s.begin(),s.end());int n=s.size();int dp[n+1][64];for(int i=0;i<=n;++i) for(int j=0;j<64;++j) dp[i][j]=0;
    dp[0][0]=1;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<64;++j)
        {
            for(int k=0;k<8;++k)
            {
                int mask=j;
                if((k&1) && s[i]=='0') mask|=8;
                else if((k&1) && s[i]=='1' && (j&8)) mask|=8;
                else if(s[i]=='0' && (j&8)) mask|=8;
                else mask-=(mask & 8);
                if((k&2) && s[i]=='0') mask|=16;
                else if((k&2) && s[i]=='1' && (j&16)) mask|=16;
                else if(s[i]=='0' && (j&16)) mask|=16;
                else mask-=(mask & 16);
                if((k&4) && s[i]=='0') mask|=32;
                else if((k&4) && s[i]=='1' && (j&32)) mask|=32;
                else if(s[i]=='0' && (j&32)) mask|=32;
                else mask-=(mask & 32);
                bool a=(k&1);bool b=(k&2);bool c=(k&4);bool d=b^c;bool e=a^c;bool f=a^b;
                if(e && f) mask|=1;
                if(d && f) mask|=2;
                if(d && e) mask|=4;
                dp[i+1][mask]+=dp[i][j];if(dp[i+1][mask]>=p) dp[i+1][mask]-=p;
            }
        }
    }
    cout<<dp[n][7];
    return 0;
}