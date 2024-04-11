#include <bits/stdc++.h>

using namespace std;
#define int long long
map <int,set<pair<int,int> > > a;
vector <int> nex;
vector <int> res1;
map <vector <int>,int> o;
set <pair<int,int> > deq;
vector <int> deq1;
int s;
int n;
vector <bool> used;
void go()
{
    if(s==2)
    {
        vector <int> v;
        for(int i=0;i<n;++i)
        {
            if(!used[i])
            {
                v.push_back(i);
                //cout<<i<<endl;
            }
        }
        //cout<<v.size()<<endl;
        nex[v[0]]=v[1];
        nex[v[1]]=v[0];
        return;
    }
    s--;
    pair <int,int> o1=(*deq.begin());
    deq.erase(deq.begin());
    int x=o1.second;
    //cout<<o1.first<<endl;
    //cout<<x<<" gfrdesw "<<endl;
    used[x]=true;
    pair <int,int> h=(*a[x].begin());
    int y=h.first;
    int z=h.second;
    //cout<<y<<" "<<z<<endl;
    //cout<<endl;
    deq.erase({deq1[y],y});
    deq.erase({deq1[z],z});
    deq1[y]--;
    deq1[z]--;
    deq.insert({deq1[y],y});
    deq.insert({deq1[z],z});
    a[y].erase({x,z});
    a[y].erase({z,x});
    a[z].erase({y,x});
    a[z].erase({x,y});
    vector <int> v;
    v.push_back(x);
    v.push_back(y);
    v.push_back(z);
    //cout<<x<<" "<<y<<" "<<z<<" rfdew "<<endl;
    sort(v.begin(),v.end());
    res1.push_back(o[v]);
    go();
    if(nex[y]==z)
    {
        nex[y]=x;
        nex[x]=z;
    }
    else
    {
        nex[z]=x;
        nex[x]=y;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int cyc=0;cyc<t;++cyc)
    {
    cin>>n;
    a.clear();
    o.clear();
    res1.clear();
    nex.clear();
    deq.clear();
    int x,y,z;
    deq1.resize(n);
    nex.resize(n);
    set <pair<int,int> > v;
    used.resize(n);
    for(int i=0;i<n;++i)
    {
        deq1[i]=0;
        used[i]=false;
    }
    for(int i=0;i<(n-2);++i)
    {
        vector <int> v1;
        cin>>x>>y>>z;
        x--;y--;z--;
        v1.push_back(x);
        v1.push_back(y);
        v1.push_back(z);
        sort(v1.begin(),v1.end());
        o[v1]=i;
        if(a.count(x)==0)
        {
            a[x]=v;
        }
        if(a.count(y)==0)
        {
            a[y]=v;
        }
        if(a.count(z)==0)
        {
            a[z]=v;
        }
        a[x].insert({y,z});
        a[y].insert({x,z});
        a[z].insert({x,y});
        a[x].insert({z,y});
        a[y].insert({z,x});
        a[z].insert({y,x});
        deq1[x]++;
        deq1[y]++;
        deq1[z]++;
    }
    /*for(int i=0;i<n;++i)
    {
        cout<<deq1[i]<<" "<<i<<endl;
    }*/
    for(int i=0;i<n;++i)
    {
        deq.insert({deq1[i],i});
    }
    s=n;
    go();
    vector <int> res;
    int t=0;
    for(int i=0;i<n;++i)
    {
        res.push_back(t);
        t=nex[t];
    }
    for(int i=0;i<res.size();++i)
    {
        cout<<res[i]+1<<" ";
    }
    cout<<endl;
    //cout<<res1.size()<<" tgfrds "<<endl;
    for(int i=0;i<res1.size();++i)
    {
        cout<<res1[i]+1<<" ";
    }
    cout<<endl;
    }
    return 0;
}