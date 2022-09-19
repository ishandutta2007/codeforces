#include <bits/stdc++.h>

using namespace std;
#define int long long
int d[26];
bool poly(string s)
{
    int n=s.size();
    for(int i=0;i<min(n,n/2+10);++i)
    {
        if(s[i]!=s[n-i-1])
        {
            return false;
        }
    }
    return true;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s;
    cin>>s;
    int n=s.size();
    for(int i=0;i<s.size();++i)
    {
        d[s[i]-'a']++;
    }
    for(int i=0;i<26;++i)
    {
        if(d[i]>=(n-1))
        {
            cout<<"Impossible";
            return 0;
        }
    }
    int ans=2;
    string s1,s2;
    string h;
    for(int i=0;i<n;++i)
    {
        s1="";s2="";
        for(int j=0;j<i;++j)
        {
            s1+=s[j];
        }
        for(int j=i;j<n;++j)
        {
            s2+=s[j];
        }
        h=(s2+s1);
        if(poly(h) && h!=s)
        {
            ans=1;
            break;
        }
    }
    cout<<ans;
    return 0;
}