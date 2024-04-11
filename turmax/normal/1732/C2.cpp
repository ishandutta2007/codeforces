#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n,q;cin>>n>>q;vector<int> pos;int a[n];int pr[n+1]={0};int xo[n+1]={0};
        for(int i=0;i<n;++i) {cin>>a[i];if(a[i]) pos.push_back(i); xo[i+1]=xo[i]^a[i];pr[i+1]=pr[i]+a[i];}
        pos.insert(pos.begin(),-1);pos.push_back(n);
        auto f=[&](int l,int r)->int
        {
            return pr[r+1]-pr[l]-(xo[r+1]^xo[l]);
        };
        while(q--)
        {
            int l,r;cin>>l>>r;--l;--r;pair<int,int> ans={l,r};
            int l1=lower_bound(pos.begin(),pos.end(),l)-pos.begin();int r1=upper_bound(pos.begin(),pos.end(),r)-pos.begin()-1;
            if(pos[r1]<l) {cout<<l+1<<' '<<l+1<<'\n';continue;}
            int f1=f(l,r);
            for(int l2=l1;l2<=l1+31;++l2)
            {
                for(int r2=r1;r2>=r1-31 && l2-l1+r1-r2<=31;--r2)
                {
                    if(l2>r2 || r2==0 || l2==pos.size()) break;
                    if(f(pos[l2],pos[r2])!=f1) break;
                    if(pos[r2]-pos[l2]<ans.second-ans.first) ans={pos[l2],pos[r2]};
                }
            }
            cout<<ans.first+1<<' '<<ans.second+1<<'\n';
        }
    }
    return 0;
}