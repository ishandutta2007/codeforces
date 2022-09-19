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
        int n;
        cin>>n;
        int curr=n;
        vector <pair<int,int> > ans;
        ans.clear();
        for(int i=(n-1);i>=1;--i)
        {
            ans.push_back({curr,i});
            curr=(curr+i+1)/2;
        }
        cout<<curr<<'\n';
        for(auto h:ans)
        {
            cout<<h.first<<' '<<h.second<<'\n';
        }
    }
    return 0;
}