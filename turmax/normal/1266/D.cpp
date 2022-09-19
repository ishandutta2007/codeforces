#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    int x,y,w;
    int val[n];
    for(int i=0;i<n;++i)
    {
        val[i]=0;
    }
    for(int i=0;i<m;++i)
    {
        cin>>x>>y>>w;
        x--;y--;
        val[x]+=w;
        val[y]-=w;
    }
    set <pair<int,int> > d;
    vector <pair<pair<int,int>,int> > res;
    for(int i=0;i<n;++i)
    {
        d.insert({val[i],i});
    }
    int val1,val2;
    set <pair<int,int> >::iterator it;
    pair <int,int> fst;
    pair <int,int> lst;
    while(!d.empty())
    {
        it=d.end();
        it--;
        lst=(*it);
        fst=(*d.begin());
        if(lst.first==0)
        {
            d.erase(lst);
            continue;
        }
        val1=lst.first;
        val2=fst.first;
        if(val1>=(-val2))
        {
            res.push_back({{lst.second,fst.second},-val2});
            d.erase(lst);
            d.erase(fst);
            d.insert({lst.first+val2,lst.second});
        }
        else
        {
            res.push_back({{lst.second,fst.second},val1});
            d.erase(lst);
            d.erase(fst);
            d.insert({fst.first+val1,fst.second});
        }
    }
    cout<<res.size()<<endl;
    for(int i=0;i<res.size();++i)
    {
        cout<<res[i].first.first+1<<" "<<res[i].first.second+1<<" "<<res[i].second<<endl;
    }
    return 0;
}