#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=998244353;
string go(string s)
{
    string ans;
    for(int i=0;i<s.size();++i)
    {
        bool h=true;
        for(int j=0;j<((i+1)/2);++j)
        {
            if(s[j]!=s[i-j])
            {
                h=false;
                break;
            }
        }
        if(h)
        {
            ans="";
            for(int j=0;j<=i;++j)
            {
                ans+=s[j];
            }
        }
    }
    reverse(s.begin(),s.end());
    for(int i=ans.size();i<s.size();++i)
    {
        bool h=true;
        for(int j=0;j<((i+1)/2);++j)
        {
            if(s[j]!=s[i-j])
            {
                h=false;
                break;
            }
        }
        if(h)
        {
            ans="";
            for(int j=0;j<=i;++j)
            {
                ans+=s[j];
            }
            reverse(ans.begin(),ans.end());
        }
    }
    return ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int q;
    cin>>q;
    while(q--)
    {
    string s;
    cin>>s;
    int n=s.size();
    int l=0;
    int r=(n-1);
    string t1;
    string t2;
    while(s[l]==s[r])
    {
        if((t1.size()+t2.size())<=(n-2))
        {
            t1+=s[l];
            t2+=s[r];
            ++l;
            r--;
        }
        else
        {
            break;
        }
    }
    string d;
    for(int i=l;i<=r;++i)
    {
        d.push_back(s[i]);
    }
    string h=go(d);
    reverse(t2.begin(),t2.end());
    cout<<t1<<h<<t2<<endl;
    }
    return 0;
}