#include <bits/stdc++.h>

using namespace std;
#define int long long
bool check(string s,int k,int l)
{
    int n=s.size();
    int t[k]={0};
    for(int i=0;i<l;++i) if(s[i]!='?') t[s[i]-'a']++;
    int dp[1<<k];vector <int> r[n];
    for(int i=0;i<(1<<k);++i) dp[i]=1e9;
    dp[0]=0;r[0].push_back(0);
    vector <int> z[k];
    for(int i=0;i<=(n-l);++i)
    {
        set <int> h;
        for(int j=0;j<k;++j) if(t[j]) h.insert(j);
        if(h.size()<2)
        {
            if(h.empty())
            {
                 for(int j=0;j<k;++j)
                 {
                     z[j].push_back(i);
                 }
            }
            else
            {
                 int j=(*h.begin());
                 {
                     z[j].push_back(i);
                 }
            }
        }
        if(s[i]!='?') t[s[i]-'a']--;
        if(i!=(n-l)) if(s[i+l]!='?') t[s[i+l]-'a']++;
    }
    for(int mask=1;mask<(1<<k);++mask)
    {
        dp[mask]=1e9;
        for(int j=0;j<k;++j)
        {
            if(mask & (1<<j))
            {
                int mask1=(mask-(1<<j));
                int o=dp[mask1];
                if(!z[j].empty() && o<=z[j].back())
                {
                    dp[mask]=min(dp[mask],(*lower_bound(z[j].begin(),z[j].end(),o)+l));
                }
            }
        }
        if(dp[mask]==1e9) return false;
    }
    return true;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    set <char> t;
    int low=0;
    int up=(n+1);
    while(true)
    {
        if((up-low)==1) {cout<<low;return 0;}
        int mid=(low+up)/2;
        if(check(s,k,mid)) low=mid;
        else up=mid;
    }
    return 0;
}