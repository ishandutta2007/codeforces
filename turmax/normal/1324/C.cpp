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
        string s;
        cin>>s;
        int n=s.size();
        vector <int> v;
        v.push_back(-1);
        for(int i=0;i<n;++i)
        {
            if(s[i]=='R')
            {
                v.push_back(i);
            }
        }
        v.push_back(n);
        int ans=(-1);
        for(int i=0;i<v.size()-1;++i)
        {
            ans=max(ans,v[i+1]-v[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}