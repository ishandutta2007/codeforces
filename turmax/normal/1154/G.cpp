#include <bits/stdc++.h>

using namespace std;
#define int long long
vector <int> b[10000001];
int c[10000001];
int t[10000001];
int lcm(int x,int y)
{
    return x*y/__gcd(x,y);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector <int> a(n);
    for(int i=0;i<=1e7;++i)
    {
        t[i]=(-1);
    }
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        t[a[i]]=i;
        b[a[i]].push_back(i);
        c[a[i]]++;
    }
    int ans=(1e18);
    pair <int,int> o;
    vector <pair<int,int> > v;
    for(int i=1;i<=1e7;++i)
    {
       v.clear();
       if(c[i]>=2)
       {
           if(i<ans)
           {
               ans=i;
               o={b[i][0],b[i][1]};
           }
           break;
       }
       for(int j=1;i*j<=1e7;++j)
       {
           if(c[i*j])
           {
               v.push_back({i*j,t[i*j]});
           }
       }
       if(v.size()==1 || v.empty())
       {
           continue;
       }
       int x=lcm(v[0].first,v[1].first);
       if(x<ans)
       {
           //cout<<i<<" "<<x<<endl;
           ans=x;
           o={v[0].second,v[1].second};
       }
    }
    cout<<min(o.first,o.second)+1<<" "<<max(o.second,o.first)+1;
    exit(0);
}