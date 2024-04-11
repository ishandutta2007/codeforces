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
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        vector <int> v;
        for(int i=0;i<s.size();++i) if(s[i]=='*') v.push_back(i);
        int beg=(*v.begin());
        int ans=1;
        while(true)
        {
            if(beg==v.back()) break;
            beg=(*(--upper_bound(v.begin(),v.end(),beg+k)));
            ++ans;
        }
        cout<<ans<<endl;
    }
    return 0;
}