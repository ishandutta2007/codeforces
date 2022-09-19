#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    //cout<<" tre "<<endl;
    int u[26];
    for(int i=0;i<26;++i)
    {
        u[i]=0;
    }
    for(int i=0;i<n;++i)
    {
        u[s[i]-'a']++;
    }
    string ans[k];
    sort(s.begin(),s.end());
    for(int i=0;i<k;++i)
    {
        ans[i]+=s[i];
    }
    for(int j=k;j<s.size();++j)
    {
        ans[0]+=s[j];
    }
    //cout<<" ytgrf de"<<endl;
    if(s[0]!=s[k-1])
    {
    cout<<ans[k-1]<<endl;
    //cout<<" ans "<<endl;
    continue;
    }
    //cout<<" trfe d"<<endl;
    string ans1[k];
    for(int j=0;j<n;++j)
    {
        ans1[j%k]+=s[j];
    }
    string h=min(*max_element(ans1,ans1+k),ans[0]);
    cout<<h<<endl;
    //cout<<" ans "<<endl;
    }
    return 0;
}