#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int cyc=0;cyc<t;++cyc)
    {
    string s,t;
    cin>>s>>t;
    vector <vector <int> > v(26);
    int n=s.size();
    for(int i=0;i<n;++i)
    {
    v[s[i]-'a'].push_back(i);
    }
    int curr=(-1);
    int h;
    int ans=0;
    int j=0;
    while(j<t.size())
    {
    if(v[t[j]-'a'].empty())
    {
    ans=(-2);
    break;
    }
    h=upper_bound(v[t[j]-'a'].begin(),v[t[j]-'a'].end(),curr)-v[t[j]-'a'].begin();
    if(h==v[t[j]-'a'].size())
    {
        //cout<<curr<<" "<<t[j]<<endl;
        curr=(-1);
        ++ans;
    }
    else
    {
        curr=v[t[j]-'a'][h];
        ++j;
    }
    }
    cout<<(ans+1)<<endl;
    }
    return 0;
}