    #include <bits/stdc++.h>

    using namespace std;
    #define int long long
    const int maxn=2e5+5;
    int32_t main()
    {
        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
        int t;
        cin>>t;
        while(t--)
        {
        int n;
        cin>>n;
        string s1,s2;
        cin>>s1>>s2;
        int u11[26];
        int u21[26];
        for(int i=0;i<26;++i)
        {
            u11[i]=0;u21[i]=0;
        }
        for(int i=0;i<n;++i)
        {
            u11[s1[i]-'a']++;
            u21[s2[i]-'a']++;
        }
        bool h=true;
        for(int i=0;i<26;++i)
        {
            if(u11[i]!=u21[i])
            {
                h=false;
                break;
            }
        }
        if(!h)
        {
            cout<<(-1)<<endl;
            continue;
        }
        int dp[n+1][n+1];
        for(int i=0;i<=n;++i)
        {
            dp[n][i]=0;
            dp[i][n]=0;
        }
        int u1[n+1][26]; for(int i=0;i<26;++i) u1[n][i]=0;
        for(int i=(n-1);i>=0;i--)
        {
            for(int j=0;j<26;++j)
            {
                u1[i][j]=u1[i+1][j];
            }
            u1[i][s1[i]-'a']++;
        }
        int u2[n+1][26]; for(int i=0;i<26;++i) u2[n][i]=0;
        for(int i=(n-1);i>=0;i--)
        {
            for(int j=0;j<26;++j)
            {
                u2[i][j]=u2[i+1][j];
            }
            u2[i][s2[i]-'a']++;
        }
        for(int i=(n-1);i>=0;i--)
        {
            for(int j=(n-1);j>=0;j--)
            {
                dp[i][j]=dp[i][j+1];
                if(u1[i][s1[i]-'a']>u2[j][s1[i]-'a'])
                {
                    //cout<<i<<" "<<j<<endl;
                    dp[i][j]=max(dp[i][j],dp[i+1][j]);
                }
                if(s1[i]==s2[j])
                {
                    dp[i][j]=max(dp[i][j],dp[i+1][j+1]+1);
                }
            }
        }
        //cout<<dp[n][n]<<" dp[n][n] "<<endl;
        cout<<(n-dp[0][0])<<endl;
        }
        return 0;
    }