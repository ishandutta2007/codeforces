#include <bits/stdc++.h>

using namespace std;
#define int long long
vector <int> d;
int m;
bool check(vector <int> z)
{
    if(z.size()*(z.size()-1)>=(2*m+10))
    {
        return false;
    }
    for(int i=0;i<z.size();++i)
    {
        for(int j=0;j<i;++j)
        {
            int o=z[i]*1e9+z[j];
            if(*(lower_bound(d.begin(),d.end(),o))!=o)
            {
                return false;
            }
        }
    }
    cout<<2<<endl;
    for(auto h:z) cout<<h+1<<' ';
    cout<<endl;
    return true;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>m>>k;
        d.clear();
        vector <int> a[n];
        int deq[n];
        bool used[n];
        for(int i=0;i<n;++i) {deq[i]=0;used[i]=false;}
        for(int i=0;i<m;++i)
        {
            int x,y;
            cin>>x>>y;
            x--;y--;
            a[x].push_back(y);a[y].push_back(x);
            deq[x]++;deq[y]++;
            d.push_back({x*1e9+y});d.push_back({y*1e9+x});
        }
        if(k==1)
        {
            cout<<2<<endl;
            cout<<1<<endl;
            continue;
        }
        sort(d.begin(),d.end());
        d.push_back(1e18);
        set <pair<int,int> > z;
        for(int i=0;i<n;++i)
        {
            z.insert({deq[i],i});
        }
        bool g=false;
        while(!z.empty())
        {
            pair <int,int> o=(*z.begin());
            used[o.second]=true;
            if(o.first>=k)
            {
                 int sum=0;
                 for(int i=0;i<n;++i) if(!used[i] || i==o.second) ++sum;
                 cout<<1<<' '<<sum<<endl;
                 for(int i=0;i<n;++i) if(!used[i] || i==o.second) cout<<i+1<<' ';
                 cout<<endl;
                 g=true;
                 break;
            }
            else if(o.first==(k-1))
            {
                vector <int> z1;
                z1.push_back(o.second);
                for(auto v:a[o.second])
                {
                    if(!used[v])
                    {
                        z1.push_back(v);
                    }
                }
                 if(z1.size()<1000 && check(z1))
                 {
                     g=true;
                     break;
                 }
                 z.erase(z.begin());
                 for(auto v:a[o.second])
                 {
                     if(used[v]) continue;
                     z.erase({deq[v],v});
                     deq[v]--;
                     z.insert({deq[v],v});
                 }
            }
            else
            {
                 z.erase(z.begin());
                 for(auto v:a[o.second])
                 {
                     if(used[v]) continue;
                     z.erase({deq[v],v});
                     deq[v]--;
                     z.insert({deq[v],v});
                 }
            }
        }
        if(!g)
        {
            cout<<(-1)<<endl;
        }
    }
    return 0;
}