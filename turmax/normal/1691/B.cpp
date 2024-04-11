#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;int a[n];int res[n];map<int,vector<int> > u;for(int i=0;i<n;++i) {cin>>a[i];u[a[i]].push_back(i);}
        bool ok=true;
        for(auto [key,val]:u)
        {
            if(val.size()==1)
            {
                cout<<(-1)<<'\n';ok=false;break;
            }
            for(int i=0;i<val.size();++i)
            {
                res[val[i]]=val[(i+1)%val.size()];
            }
        }
        if(ok) {for(int i=0;i<n;++i) cout<<res[i]+1<<' '; cout<<'\n';}
    }
    return 0;
}