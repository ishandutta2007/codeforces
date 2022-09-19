#include <bits/stdc++.h>

using namespace std;
#define int long long
int go(string s)
{
    int ans=0;
    deque <int> q;
    for(int i=0;i<s.size();++i)
    {
        if(s[i]=='(') q.push_back(i);
        else
        {
            if(q.empty()) continue;
            ++ans;
            q.pop_back();
        }
    }
    return ans;
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
        int n=s.size();
        string s1,s2;
        for(int i=0;i<n;++i)
        {
            if(s[i]=='(' || s[i]==')') s1+=s[i];
            else s2+=s[i];
        }
        for(int i=0;i<s2.size();++i)
        {
            if(s2[i]=='[') s2[i]='(';
            else s2[i]=')';
        }
        cout<<go(s1)+go(s2)<<endl;
    }
    return 0;
}