#include <bits/stdc++.h>

using namespace std;
#define int long long
map <char,int> u;
pair<int,string> go(vector <char> v,string s)
{
    int n=s.size();
    string s1="";
    for(auto h:v)
    {
        int cnt=u[h];
        for(int i=0;i<cnt;++i) s1+=h;
    }
    int res=0;
    int cnt=(-1);
    for(int i=0;i<n;++i)
    {
        if(s[i]==v[3])
        {
            ++cnt;
            res+=(s.size()-u[v[3]]+cnt-i);
        }
    }
    cnt=0;
    int cnt1=0;
    for(int i=0;i<n;++i)
    {
        if(s[i]==v[0] || s[i]==v[1] || s[i]==v[2])
        {
            ++cnt1;
        }
        if(s[i]==v[2])
        {
            ++cnt;
            res+=(s.size()-u[v[3]]-u[v[2]]+cnt-cnt1);
        }
    }
    cnt=0;cnt1=0;
    for(int i=0;i<n;++i)
    {
        if(s[i]==v[0] || s[i]==v[1])
        {
            ++cnt1;
        }
        if(s[i]==v[1])
        {
            ++cnt;
            res+=(u[v[0]]+cnt-cnt1);
        }
    }
    return {res,s1};
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        vector <char> v={'A','N','T','O'};
        sort(v.begin(),v.end());
        for(auto h:v) u[h]=0;
        for(auto h:s) u[h]++;
        pair<int,string> ans=go(v,s);
        while(next_permutation(v.begin(),v.end()))
        {
            ans=max(ans,go(v,s));
        }
        cout<<ans.second<<endl;
    }
    return 0;
}