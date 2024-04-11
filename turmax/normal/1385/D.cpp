#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=200000;
int dp[maxn][20];
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int po[20];
    int u1=1;
    for(int i=0;i<20;++i)
    {
        po[i]=u1;
        u1*=2;
    }
    int t;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    char c[20];
    int o=0;
    while(po[o]!=n)
    {
        ++o;
    }
    char g='a';
    for(int i=o;i>=0;i--)
    {
        c[i]=g;
        ++g;
    }
    string s;
    cin>>s;
    for(int j=0;po[j]<=n;++j)
    {
        char l=c[j];
        for(int i=0;(i+po[j])<=n;i+=po[j])
        {
            if(j==0)
            {
                if(s[i]==l)
                dp[i][j]=0;
                else
                dp[i][j]=1;
            }
            else
            {
                int tl=i;
                int tm=(i+po[j-1]);
                int tr=(i+po[j]);
                int h1=0,h2=0;
                for(int k=tl;k<tm;++k)
                {
                    if(s[k]!=l)
                    {
                        ++h1;
                    }
                }
                for(int k=tm;k<tr;++k)
                {
                    if(s[k]!=l)
                    {
                        ++h2;
                    }
                }
                dp[i][j]=min(dp[tm][j-1]+h1,dp[tl][j-1]+h2);
            }
        }
    }
    cout<<dp[0][o]<<endl;
    }
    return 0;
}