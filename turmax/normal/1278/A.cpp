#include <bits/stdc++.h>

using namespace std;
#define int long long
bool per(string s1,string s2)
{
    int a=s1.size();
    int a1[26];
    int a2[26];
    for(int i=0;i<26;++i)
    {
        a1[i]=0;
        a2[i]=0;
    }
    for(int i=0;i<a;++i)
    {
        a1[s1[i]-'a']++;
        a2[s2[i]-'a']++;
    }
    for(int i=0;i<26;++i)
    {
        if(a1[i]!=a2[i])
        {
            return false;
        }
    }
    return true;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int cyc=0;cyc<t;++cyc)
    {
    string s1,s2;
    cin>>s1>>s2;
    string s;
    bool ans=false;
    if(s1.size()>s2.size())
    {
        cout<<"NO"<<endl;
        continue;
    }
    for(int i=0;i<=(s2.size()-s1.size());++i)
    {
        s="";
        for(int j=0;j<s2.size();++j)
        {
            s+=s2[i+j];
        }
        if(per(s1,s))
        {
            ans=true;
            break;
        }
    }
    if(ans)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    }
    return 0;
}