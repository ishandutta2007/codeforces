#include <bits/stdc++.h>

using namespace std;
//#define int long long
int curr;
vector <int> num;
vector <int> res;
vector <pair<int,int> > ed1;
int corn;
int f;
vector <vector <int> > g;
void go(vector <vector <int> > v,vector <int> z,int pr)
{
    vector <vector <int> > ed;
    if(v.size()==1)
    {
        //cout<<z[0]<<" z[0] "<<endl;
        if(pr!=(-1))
        ed1.push_back({z[0],pr});
        res.push_back(v[0][0]);
        num.push_back(z[0]);
        return;
    }
    num.push_back(curr);
    int ma=0;
    for(auto h:v)
    {
        for(auto h1:h)
        {
            ma=max(ma,h1);
        }
    }
    ed.clear();
    ed.resize(v.size());
    for(int i=0;i<v.size();++i)
    {
        for(int j=0;j<v.size();++j)
        {
            if(v[i][j]==ma)
            {
                ed[i].push_back(j);
                ed[j].push_back(i);
            }
        }
    }
    res.push_back(ma);
    if(pr==(-1)) corn=curr;
    if(pr!=(-1))
    ed1.push_back({curr,pr});
    int pr1=curr;
    curr--;
    bool ok[v.size()];
    bool ok1[v.size()];
    for(int i=0;i<v.size();++i) ok1[i]=false;
    vector <int> v2;
    for(int i=0;i<v.size();++i)
    {
        v2.clear();
        //cout<<i<<" i "<<endl;
        if(ok1[i]) continue;
        for(int j=0;j<v.size();++j) ok[j]=true;
        for(auto h:ed[i])
        {
            ok[h]=false;
        }
        for(int j=0;j<v.size();++j)
        {
            if(ok[j] || j==i)
            {
                v2.push_back(j);
            }
        }
        g.clear();
        for(auto z1:v2) ok1[z1]=true;
        vector <int> z2;
        for(auto l:v2)
        {
            z2.push_back(z[l]);
        }
        for(auto l1:v2)
        {
            vector <int> o;
            for(auto l2:v2)
            {
                o.push_back(v[l1][l2]);
            }
            g.push_back(o);
        }
        go(g,z2,pr1);
    }
}
bool cmp(pair <int,int> u,pair <int,int> v)
{
    return u.second<v.second;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    curr=1e9;
    f=n;
    vector <vector <int> > a(n);
    for(int i=0;i<n;++i) a[i].resize(n);
    for(int i=0;i<n;++i) for(int j=0;j<n;++j) cin>>a[i][j];
    vector <int> z(n);
    for(int i=1;i<=n;++i) z[i-1]=i;
    go(a,z,-1);
    map <int,int> u;
    vector <pair<int,int> > res1;
    for(int i=0;i<res.size();++i) res1.push_back({res[i],num[i]});
    cout<<res1.size()<<endl;
    sort(res1.begin(),res1.end(),cmp);
    for(int i=0;i<num.size();++i) u[res1[i].second]=(i+1);
    //reverse(res1.begin(),res1.end());
    for(int i=0;i<res1.size();++i) cout<<res1[i].first<<' ';
    cout<<endl;
    cout<<(res1.size())<<endl;
    for(auto h:ed1)
    {
        cout<<u[h.first]<<' '<<u[h.second]<<endl;
    }
    return 0;
}