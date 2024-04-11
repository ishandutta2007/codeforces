#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector <int> a(n);
    for(int i=0;i<n;++i) cin>>a[i];
    while(!a.empty() && a.back()==0)
    {
        a.pop_back();
    }
    if(!a.empty() && a.back()!=1)
    {
        cout<<(-1);
        return 0;
    }
    vector <int> tw;
    vector <pair<int,int> > u;
    vector <int> z;
    vector <int> h;
    bool used[n];
    for(int i=0;i<a.size();++i)
    {
        used[i]=false;
        if(a[i]==0) continue;
        if(a[i]==1)
        {
            if(tw.size())
            {
                u.push_back({tw.back(),i});
                tw.pop_back();
                used[i]=true;
            }
            else
            {
                z.push_back(i);
            }
        }
        else if(a[i]==2)
        {
            tw.push_back(i);
        }
        else
        {
            h.push_back(i);
        }
    }
    if(tw.size())
    {
        cout<<(-1);
        return 0;
    }
    int curr=n;
    vector <pair<int,int> > res;
    for(auto v:h)
    {
        for(int i=(v+1);i<=a.size();++i)
        {
            if(i==a.size())
            {
                cout<<(-1);
                return 0;
            }
            if(a[i] && !used[i])
            {
                res.push_back({curr,v});res.push_back({curr,i});
                curr--;
                break;
            }
        }
    }
    for(auto l:u)
    {
        res.push_back({curr,l.first});res.push_back({curr,l.second});
        curr--;
        continue;
    }
    for(auto l:z)
    {
        res.push_back({curr,l});
        curr--;
        continue;
    }
    cout<<res.size()<<endl;
    for(auto v:res)
    {
        cout<<n+1-v.first<<' '<<v.second+1<<endl;
    }
    return 0;
}