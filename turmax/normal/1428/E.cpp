#include <bits/stdc++.h>

using namespace std;
#define int long long
int f(int x,int l)
{
    if(l>x)
    {
        return 1e18;
    }
    int o1=(x/l);
    int c2=(x%l);
    int c1=l-c2;
    int o2=o1+1;
    return o1*o1*c1+o2*o2*c2;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,k;
    cin>>n>>k;
    vector <int> a(n);
    vector <int> c(n);
    vector <int> b(n);
    set <pair<int,int> > d;
    for(int i=0;i<n;++i) cin>>a[i];
    for(int i=0;i<n;++i)
    {
        b[i]=1;
        c[i]=f(a[i],2)-f(a[i],1);
        d.insert({c[i],i});
    }
    for(int i=0;i<(k-n);++i)
    {
        pair <int,int> curr=*d.begin();
        b[curr.second]++;
        d.erase(d.begin());
        c[curr.second]=f(a[curr.second],b[curr.second]+1)-f(a[curr.second],b[curr.second]);
        d.insert({c[curr.second],curr.second});
    }
    int ans=0;
    for(int i=0;i<n;++i)
    {
        ans+=f(a[i],b[i]);
    }
    cout<<ans;
    return 0;
}