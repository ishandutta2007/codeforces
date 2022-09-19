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
        int n,m,k;
        cin>>n>>m>>k;
        int a[n],b[m];
        for(int i=0;i<n;++i) cin>>a[i];
        for(int i=0;i<m;++i) cin>>b[i];
        sort(a,a+n);sort(b,b+m);
        int cnta[n]={0};int cntb[m]={0};
        map <pair<int,int>,int> da;
        map <pair<int,int>,int> db;
        for(int i=0;i<k;++i)
        {
            int x,y;
            cin>>x>>y;
            bool h1=upper_bound(a,a+n,x)-lower_bound(a,a+n,x);bool h2=upper_bound(b,b+m,y)-lower_bound(b,b+m,y);
            if(h1 && h2) continue;
            if(!h1 && !h2) assert(false);
            if(h1)
            {
                 int o1=lower_bound(a,a+n,x)-a;
                 int o2=lower_bound(b,b+m,y)-b;
                 if(da.count({o1,o2})) da[{o1,o2}]++;
                 else da[{o1,o2}]=1;
                 cntb[lower_bound(b,b+m,y)-b]++;
            }
            else
            {
                 int o1=lower_bound(a,a+n,x)-a;
                 int o2=lower_bound(b,b+m,y)-b;
                 if(db.count({o1,o2})) db[{o1,o2}]++;
                 else db[{o1,o2}]=1;
                 cnta[lower_bound(a,a+n,x)-a]++;
            }
        }
        int ans=0;
        for(int i=0;i<n;++i) ans+=cnta[i]*(cnta[i]-1)/2;
        for(int i=0;i<m;++i) ans+=cntb[i]*(cntb[i]-1)/2;
        for(auto [h1,h2]:da) ans-=h2*(h2-1)/2;
        for(auto [h1,h2]:db) ans-=h2*(h2-1)/2;
        cout<<ans<<'\n';
    }
    return 0;
}