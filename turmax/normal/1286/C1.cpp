#include <bits/stdc++.h>

using namespace std;
#define int long long
bool comp(string s1,string s2)
{
    return s1.size()<s2.size();
}
int cou(string s,char x)
{
    int t=0;
    for(int i=0;i<s.size();++i)
    {
        if(s[i]==x)
        {
            ++t;
        }
    }
    return t;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector <string> s1,s2;
    cout<<"?"<<" "<<1<<" "<<n<<endl;
    s1.resize(n*(n+1)/2);
    for(int i=0;i<(n*(n+1))/2;++i)
    {
        cin>>s1[i];
        sort(s1[i].begin(),s1[i].end());
    }
    if(n==1)
    {
        cout<<'!'<<" "<<s1[0];
        return 0;
    }
    cout<<"?"<<" "<<2<<" "<<n<<endl;
    s2.resize(n*(n-1)/2);
    for(int i=0;i<(n*(n-1))/2;++i)
    {
        cin>>s2[i];
        sort(s2[i].begin(),s2[i].end());
    }
    multiset <string> u1,u2;
    for(int i=0;i<s1.size();++i)
    {
        u1.insert(s1[i]);
    }
    for(int i=0;i<s2.size();++i)
    {
        u2.insert(s2[i]);
    }
    vector <string> a1;
    set <string> h;
    for(int i=0;i<s1.size();++i)
    {
        if(u1.count(s1[i])>u2.count(s1[i]) && !h.count(s1[i]))
        {
            a1.push_back(s1[i]);
            h.insert(s1[i]);
        }
    }
    vector <string> a=a1;
    sort(a.begin(),a.end(),comp);
    int u[26];
    for(int i=0;i<26;++i)
    {
        u[i]=0;
    }
    string s;
    string ans;
    for(int i=0;i<a.size();++i)
    {
        s=a[i];
        for(int i=0;i<26;++i)
        {
            if(cou(s,'a'+i)>u[i])
            {
                u[i]=cou(s,'a'+i);
                ans+=('a'+i);
                break;
            }
        }
    }
    cout<<"!"<<" "<<ans<<endl;
    return 0;
}