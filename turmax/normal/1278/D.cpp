#include <bits/stdc++.h>

using namespace std;
#define int long long
bool comp(pair <int,int> a1,pair <int,int> a2)
{
    return a1.second<a2.second;
}
vector <int> parent;
vector <int> lp;
unordered_map <int,int> o;
int glav(int x)
{
    int y=x;
    while(true)
    {
        if(parent[y]==(-1))
        {
            return y;
        }
        y=parent[y];
    }
}
void go(int x,int y)
{
    if(o.count(1e9*x+y))
    {
        return;
    }
    o[1e9*x+y]=1;
    x=glav(x);
    y=glav(y);
    if(x==y)
    {
        cout<<"NO";
        exit(0);
    }
    if(lp[x]>=lp[y])
    {
        parent[y]=x;
        lp[x]+=lp[y];
    }
    else
    {
        parent[x]=y;
        lp[y]+=lp[x];
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    parent.resize(n);
    lp.resize(n);
    vector <int> next(n);
    vector <int> last(n);
    for(int i=0;i<n;++i)
    {
        lp[i]=1;
        parent[i]=(-1);
        next[i]=(i+1);
        last[i]=(i-1);
    }
    vector <pair<int,int> > a(n);
    vector <pair<int,int> > b(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i].first>>a[i].second;
        b[i].first=a[i].first;
        b[i].second=a[i].second;
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end(),comp);
    //cout<<b[0].first<<" "<<b[0].second<<" tgfrde "<<endl;
    int l,r;
    int l1,r1;
    int t;
    int d;
    for(int i=0;i<b.size();++i)
    {
        l=b[i].first;
        r=b[i].second;
        t=lower_bound(a.begin(),a.end(),make_pair(l,r))-a.begin();
        l1=upper_bound(a.begin(),a.end(),(pair <int,int>) make_pair(l+1,-1e18))-a.begin();
        r1=upper_bound(a.begin(),a.end(),(pair<int,int>) make_pair(r+1,-1e18))-a.begin();
        d=l1;
        while(d<r1)
        {
            if(a[d].second>a[t].second)
            {
            //cout<<j<<" "<<t<<endl;
            go(d,t);
            }
            //cout<<j<<" "<<t<<endl;
            d=next[d];
        }
        if(last[t]>=0)
        {
        next[last[t]]=next[t];
        }
        if(next[n]<n)
        {
        last[next[t]]=last[t];
        }
    }
    if(o.size()==(n-1))
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }
    return 0;
}