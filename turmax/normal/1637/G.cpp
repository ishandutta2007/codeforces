#include <bits/stdc++.h>

using namespace std;
#define int long long
vector<pair<int,int> > f(int n,int o)
{
    if(n<=0) return {};
    if(n==1)
    {
        vector<pair<int,int> > res;
        while(n!=o)
        {
            res.push_back({0,n});
            res.push_back({n,n});
            n*=2;
        }
        return res;
    }
    if(n==2 && o==2)
    {
        return {{0,1},{1,1}};
    }
    if(n==3 && o==4)
    {
        return {{1,3},{2,2},{0,4}};
    }
    if(n==4 && o==4)
    {
        return {{1,3},{2,2},{0,4}};
    }
    if(n==5 && o==8)
    {
        return {{3,5},{2,2},{4,4},{0,1},{1,1},{0,2},{2,2},{0,4},{4,4},{0,8},{0,8}};
    }
    if(n==6 && o==8)
    {
        return {{3,5},{2,6},{4,4},{0,1},{1,1},{2,2},{0,4},{4,4},{0,8},{0,8}};
    }
    if(n==o)
    {
        return f(n-1,o);
    }
    if(o>=2*n)
    {
        vector <pair<int,int> > res=f(n,o/2);
        while(n>=4)
        {
            res.push_back({o/2,o/2});
            res.push_back({0,o});
            n-=2;
        }
        if(n==3)
        {
            res.push_back({o/2,o/2});
            res.push_back({0,o/2});
            res.push_back({o/2,o/2});
            res.push_back({0,o});
        }
        else if(n==2)
        {
            res.push_back({o/2,o/2});
            res.push_back({0,o});
        }
        return res;
    }
    vector<pair<int,int> > res;
    for(int i=o-n;i<o/2;++i)
    {
        res.push_back({i,o-i});
    }
    vector<pair<int,int> > res1=f(o-n-1,o);vector<pair<int,int> > res2=f(n-o/2,o/2);
    for(auto &t:res2) {t.first*=2;t.second*=2;}
    if(n-o/2>2)
    {
        res2.pop_back();
        for(auto h:res2) res.push_back(h);
        for(auto h:res1) res.push_back(h);
        res.push_back({0,o/2});res.push_back({o/2,o/2});
        res.push_back({0,o});
        return res;
    }
    else if(o-n-1>2)
    {
        res1.pop_back();
        for(auto h:res1) res.push_back(h);
        for(auto h:res2) res.push_back(h);
        res.push_back({0,o/2});res.push_back({o/2,o/2});
        res.push_back({0,o});
        return res;
    }
    assert(false);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;while(t--)
    {
        int n;cin>>n;
        if(n==2) {cout<<(-1)<<'\n';continue;}
        int o=n;while(__builtin_popcount(o)!=1) ++o;
        vector<pair<int,int> > res=f(n,o);
        cout<<res.size()<<'\n';
        for(auto h:res) cout<<h.first<<' '<<h.second<<'\n';
    }
    return 0;
}