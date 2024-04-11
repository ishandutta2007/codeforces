#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;int a[n];vector<int> v0,v1;for(int i=0;i<n;++i) {cin>>a[i];if(a[i]==0) v0.push_back(i); else v1.push_back(i);}
        reverse(v1.begin(),v1.end());reverse(v0.begin(),v0.end());
        int ans=1e18;int cur=0;
        while(true)
        {
            while(!v0.empty() && !v1.empty() && v1.back()>v0.back())
            {
                v0.pop_back();continue;
            }
            if(cur>=v0.size() || v1.empty()) {ans=min(ans,cur);break;}
            ++cur;v1.pop_back();
            if(cur>=v0.size() || v1.empty()) {ans=min(ans,cur);break;}
        }
        cout<<ans<<'\n';
    }
    return 0;
}