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
    int n,x,y;
    cin>>n>>x>>y;
    int a[n];
    vector <pair<int,int> > v;
    int u[n+1];
    for(int i=0;i<=n;++i) u[i]=0;
    vector <int> z[n+1];
    for(int i=0;i<n;++i) {cin>>a[i];a[i]--;u[a[i]]++;z[a[i]].push_back(i);}
    set <pair<int,int> > d;
    for(int i=0;i<=n;++i)
    {
        //cout<<i<<" i "<<u[i]<<" u[i] "<<endl;
        d.insert({-u[i],i});
    }
    int el=0;
    for(int i=0;i<=n;++i)
    {
        if(!u[i])
        {
            el=i;
            break;
        }
    }
    bool used[n];
    for(int i=0;i<n;++i) used[i]=false;
    for(int i=0;i<x;++i)
    {
        pair <int,int> o=(*d.begin());
        d.erase(d.begin());
        //cout<<o.second<<" o.second "<<endl;
        int u1=z[o.second].back();
        z[o.second].pop_back();
        u[o.second]--;
        d.insert({-u[o.second],o.second});
        used[u1]=true;
    }
    int res[n];
    for(int i=0;i<n;++i)
    {
        if(!used[i])
        {
            //cout<<a[i]<<" a[i] "<<i<<" i "<<endl;
            v.push_back({a[i],i});
        }
        else
        {
            res[i]=a[i];
        }
    }
    int l=v.size();
    //cout<<l<<" l "<<endl;
    sort(v.begin(),v.end());
    vector <int> g;
    for(int i=0;i<v.size();++i)
    {
        g.push_back(v[i].first);
    }
    for(int i=0;i<v.size();++i)
    {
        v[i].first=g[(i+(l/2))%v.size()];
    }
    for(int i=0;i<v.size();++i)
    {
        res[v[i].second]=v[i].first;
    }
    int x1=0,y1=0;
    int may=n;
    for(int i=0;i<n;++i)
    {
        if(res[i]==a[i] && !used[i])
        {
            res[i]=el;
            may--;
        }
    }
    int u2[n+1];
    for(int i=0;i<=n;++i) {u2[i]=0;u[i]=0;}
    for(int i=0;i<n;++i) {u2[res[i]]++;u[a[i]]++;}
    for(int i=0;i<n;++i)
    {
        if(res[i]==a[i])
        {
            ++x1;
        }
    }
    for(int i=0;i<=n;++i)
    {
        y1+=min(u[i],u2[i]);
    }
    //cout<<" res "<<endl;
    //for(int i=0;i<n;++i) cout<<res[i]<<' ';
    //cout<<endl;
    //cout<<x1<<" "<<y1<<" x1y1 "<<endl;
    if(x1>x || y>may)
    {
        cout<<"NO"<<endl;
        continue;
    }
    for(int i=0;i<n;++i)
    {
        if(y1>y && res[i]!=a[i])
        {
            y1-=min(u2[res[i]],u[res[i]]);
            u2[res[i]]--;
            y1+=min(u2[res[i]],u[res[i]]);
            res[i]=el;
            y1-=min(u2[el],u[el]);
            u2[el]++;
            y1+=min(u2[el],u[el]);
        }
    }
    cout<<"YES"<<endl;
    for(int i=0;i<n;++i)
    {
        cout<<res[i]+1<<' ';
    }
    cout<<endl;
    }
    return 0;
}