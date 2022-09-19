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
        int n,m;
        cin>>n>>m;
        int b[n];
        int d[m];
        for(int i=0;i<m;++i) d[i]=0;
        for(int i=0;i<n;++i) {cin>>b[i];b[i]--;d[b[i]]++;}
        sort(b,b+n);
        int a[m];
        for(int i=0;i<m;++i) cin>>a[i];
        int ans=0;
        set <pair<int,int> > o;
        for(int i=0;i<n;++i) ans+=a[b[i]];
        int cyc=0;
        for(int i=(m-1);i>=0;i--)
        {
            for(int j=0;j<d[i];++j)
            {
                ++cyc;
                o.insert({-a[i],cyc});
            }
            if(o.empty()) continue;
            pair <int,int> h=(*o.begin());
            ans-=((-h.first)-min(-h.first,a[i]));
            h.first=(-a[i]);
            o.erase(o.begin());
            o.insert(h);
        }
        cout<<ans<<'\n';
    }
    return 0;
}