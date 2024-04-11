#include <bits/stdc++.h>

using namespace std;
#define int long long
pair <int,int> inv(pair<int,int> a)
{
    return {a.second,a.first};
}
bool comp(pair<int,int> a,pair<int,int> b)
{
    return inv(a)<inv(b);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    map <pair<int,int>,int> h;
    for(int cyc=0;cyc<t;++cyc)
    {
    h.clear();
    int s=0;
    int n;
    cin>>n;
    vector <pair<int,int> > a(n);
    vector <int> c;
    map <int,int> o;
    o.clear();
    map <int,int> m;
    map <int,int> h;
    map <int,int> z;
    set <int> be;
    set <int> en;
    set <int> r;
    for(int i=0;i<n;++i)
    {
        cin>>a[i].first>>a[i].second;
        be.insert(a[i].first);
        en.insert(a[i].second);
        if(!o.count(a[i].first))
        {
        c.push_back(a[i].first);
        o[a[i].first]=1;
        }
        if(!o.count(a[i].second))
        {
        c.push_back(a[i].second);
        o[a[i].second]=1;
        }
    }
    vector <pair<int,int> > b=a;
    sort(b.begin(),b.end(),comp);
    sort(a.begin(),a.end());
    int curr1=(-1e18);
    int curr2=1e18;
    vector <bool> used(n);
    for(int i=0;i<n;++i)
    {
        used[i]=false;
    }
    for(int i=0;i<n;++i)
    {
        if(curr1>=a[i].first)
        {
            used[i]=true;
        }
        curr1=max(a[i].second,curr1);
    }
    for(int i=(n-1);i>=0;i--)
    {
        if(curr2<=a[i].second)
        {
            used[i]=true;
        }
        curr2=min(curr2,a[i].first);
    }
    set <int> e;
    sort(c.begin(),c.end());
    int l=0;
    int u;
    bool t;
    int g;
    for(int i=0;i<c.size();++i)
    {
        while(l<n && a[l].first==c[i])
        {
            e.insert(a[l].second);
            if(!m.count(a[l].second))
            {
                m[a[l].second]=1;
            }
            else
            {
                m[a[l].second]++;
            }
            h[a[l].second]=l;
            ++l;
        }
        t=e.count(c[i]);
        e.erase(c[i]);
        if(e.size()==1 && t && en.count(c[i]) && (i<=(c.size()-1)) && be.count(c[i+1]))
        {
            u=(*e.begin());
            //cout<<u<<" u "<<endl;
            if(m[u]==1)
            {
                g=h[u];
                if(!z.count(h[u]))
                {
                    z[h[u]]=1;
                }
                else
                {
                    z[h[u]]++;
                }
            }
        }
        else if(e.empty())
        {
            ++s;
        }
    }
    int ma=(-1);
    //cout<<e.size()<<endl;
    //cout<<s<<" s "<<endl;
    for(int i=0;i<n;++i)
    {
        if(used[i])
        {
            ma=max(ma,0LL);
        }
        if(z.count(i))
        {
            ma=max(ma,z[i]);
        }
    }
    //cout<<ma<<" "<<s<<endl;
    cout<<s+ma<<endl;
    }
    return 0;
}