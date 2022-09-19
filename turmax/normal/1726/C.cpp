#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;string s;cin>>s;set<int> res;
        stack<int> u;u.push(-1);for(int i=0;i<2*n;++i) {if(s[i]=='(') u.push(i); else {u.pop();res.insert(u.top());}}
        cout<<res.size()<<'\n';
    }
    return 0;
}