#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=1e9+7;
const int maxn=1e3+5;
int po[maxn];
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int inv9=(p+1)/9;
    assert((p+1)%9==0);
    po[0]=1;for(int i=1;i<maxn;++i) po[i]=(po[i-1]*10)%p;
    string s;
    cin>>s;
    string t=s;
    reverse(t.begin(),t.end());
    int n=s.size();
    int ans=0;
    for(int j=1;j<=9;++j)
    {
        int dp[n+1][2];
        for(int i=0;i<t.size();++i)
        {
            int o=t[i]-'0';
            ans-=((o*po[i])%p)*inv9;
            ans%=p;
        }
        dp[0][0]=0;dp[0][1]=1;
        for(int i=0;i<n;++i)
        {
            dp[i+1][0]=0;dp[i+1][1]=0;
            int o=s[i]-'0';
            for(int l=0;l<10;++l)
            {
                if(l<o)
                {
                    if(l>=j)
                    {
                        dp[i+1][0]+=((dp[i][0]+dp[i][1])*10);
                    }
                    else
                    {
                        dp[i+1][0]+=(dp[i][0]+dp[i][1]);
                    }
                }
                else if(l>o)
                {
                    if(l>=j)
                    {
                        dp[i+1][0]+=((dp[i][0])*10);
                    }
                    else
                    {
                        dp[i+1][0]+=(dp[i][0]);
                    }
                }
                else
                {
                    if(l>=j)
                    {
                        dp[i+1][0]+=((dp[i][0])*10);
                        dp[i+1][1]+=((dp[i][1])*10);
                    }
                    else
                    {
                        dp[i+1][0]+=(dp[i][0]);
                        dp[i+1][1]+=(dp[i][1]);
                    }
                }
            }
            dp[i+1][0]%=p;dp[i+1][1]%=p;
        }
        int r=(dp[n][0]+dp[n][1]);r%=p;r*=inv9;r%=p;
        ans+=r;ans%=p;
    }
    ans--;
    cout<<(ans%p+p)%p;
    return 0;
}