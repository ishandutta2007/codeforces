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
    string s;
    cin>>s;
    set <int> h;
    for(int i=0;i<s.size();++i)
    {
        h.insert(s[i]-'0');
    }
    if(h.size()==1)
    {
        cout<<s<<endl;
        continue;
    }
    for(int i=0;i<s.size();++i)
    {
        cout<<'0'<<'1';
    }
    cout<<endl;
    }
    return 0;
}