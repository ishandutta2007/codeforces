#include <bits/stdc++.h>

using namespace std;
#define int long long
int u[26];
int t[26][26];
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s;
    cin>>s;
    int n=s.size();
    for(int i=0;i<n;++i)
    {
        u[s[i]-'a']++;
        int x=s[i]-'a';
        for(int j=0;j<26;++j)
        {
            t[x][j]+=(u[j]);
        }
    }
    int ans=0;
    for(int i=0;i<26;++i)
    {
        ans=max(ans,u[i]);
        for(int j=0;j<i;++j)
        {
            ans=max(ans,max(t[i][j],t[j][i]));
        }
        ans=max(ans,(u[i]*(u[i]-1))/2);
    }
    cout<<ans;
    return 0;
}