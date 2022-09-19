#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=1e6+5;
int pr[maxn];
int f(pair<pair<int,int>,int> o)
{
    int l=o.first.first;int r=o.first.second;
    //cout<<l<<" l "<<r<<" r "<<o.second<<endl;
    //cout<<(pr[r]-pr[r-o.second])<<" res1 "<<endl;
    return pr[r]-pr[r-o.second];
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m,q;
    cin>>n>>m>>q;
    int a[n],b[m],c[q];
    vector <pair<int,bool> > d;
    for(auto &h:a) cin>>h; for(auto &h:b) cin>>h; for(auto &h:c) cin>>h;
    for(auto h:a) d.push_back({h,true}); for(auto h:b) d.push_back({h,false});
    sort(d.begin(),d.end());
    pr[0]=0;for(int i=0;i<d.size();++i) pr[i+1]=pr[i]+d[i].first;
    vector <pair<int,int> > o;
    for(int i=1;i<d.size();++i) o.push_back({d[i].first-d[i-1].first,i-1});
    sort(o.begin(),o.end());
    map <int,int> res;int sum=0;for(auto h:a) sum+=h;
    res[0]=sum;set <int> keys;keys.insert(0);
    set <pair<pair<int,int>,int> > z;
    //cout<<d.size()<<" d.size() "<<endl;
    for(int i=0;i<d.size();++i) z.insert({{i,i+1},d[i].second});
    int ans=sum;
    for(auto h:o)
    {
        //for(auto h1:z)
       // {
        //    cout<<h1.first.first<<' '<<h1.first.second<<' '<<h1.second<<endl;
        //}
        //cout<<" z "<<endl;
        int val=h.first;
        int l=h.second;int r=l+1;
        //cout<<l<<' '<<r<<endl;
        set <pair<pair<int,int>,int> >::iterator it=(z.lower_bound(make_pair(make_pair(r,(int) -1),(int) -1)));
        assert(it!=z.end());
        ans-=f(*it);--it;ans-=f(*it);
        pair<pair<int,int>,int> o1=(*it);++it;pair<pair<int,int>,int> o2=(*it);
        z.erase(o1);z.erase(o2);z.insert({{o1.first.first,o2.first.second},o1.second+o2.second});
        ans+=f({{o1.first.first,o2.first.second},o1.second+o2.second});
        //cout<<ans<<" ans "<<endl;
       // cout<<val<<" val "<<endl;
        res[val]=ans;keys.insert(val);
    }
    keys.insert(1e18);res[1e18]=ans;
    for(int i=0;i<q;++i)
    {
        set <int>::iterator it=keys.upper_bound(c[i]);
        --it;
        cout<<res[(*it)]<<'\n';
    }
    return 0;
}