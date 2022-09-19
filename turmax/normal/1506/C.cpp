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
        string s1,s2;
        cin>>s1>>s2;
        int ans=s1.size()+s2.size();
        for(int l=1;l<=min(s1.size(),s2.size());++l)
        for(int i=0;i<=(s1.size()-l);++i)
        for(int j=0;j<=(s2.size()-l);++j)
        if(s1.substr(i,l)==s2.substr(j,l))
        ans=min(ans,s1.size()+s2.size()-2*l);
        cout<<ans<<endl;
    }
    return 0;
}