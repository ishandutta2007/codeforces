#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=1e5+5;
pair<int,int> b[maxn];
int f1(vector<int> a)
{
    int n=a.size();
    int lowl=0;int upl=2e9;
    while(upl-lowl>1)
    {
        int mid=(lowl+upl)/2;
         b[0]={0,0};
         bool ok=true;
        for(int i=1;i<n-1;++i)
        {
        int l1=b[i-1].first+mid;l1=max(l1,a[i]);
        int r1=b[i-1].second+2e9;r1=min(r1,a[i+1]);
        if(l1>a[i+1]) ok=false;
        b[i]={l1,r1};
        }
        if(ok && b[n-2].second==a[n-1])
        {
            lowl=mid;
        }
        else
        {
            upl=mid;
        }
    }
    return lowl;
}
int f2(vector<int> a)
{
    int n=a.size();
    int lowr=0;int upr=2e9;
    while(upr-lowr>1)
    {
        int mid=(lowr+upr)/2;
         b[0]={0,0};
         bool ok=true;
        for(int i=1;i<n-1;++i)
        {
        int l1=b[i-1].first+0;l1=max(l1,a[i]);
        int r1=b[i-1].second+mid;r1=min(r1,a[i+1]);
        if(r1<a[i]) ok=false;
        b[i]={l1,r1};
        }
        if(ok && b[n-2].second==a[n-1])
        {
            upr=mid;
        }
        else
        {
            lowr=mid;
        }
    }
    return upr;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int le,n;cin>>le>>n;
    vector<int> a(n);for(int i=0;i<n;++i) cin>>a[i]; a.insert(a.begin(),0);a.push_back(le);
    n=a.size();
    int l=f1(a);int r=f2(a);
    pair<int,int> b[n-1];
    b[0]={0,0};
    for(int i=1;i<n-1;++i)
    {
        int l1=b[i-1].first+l;l1=max(l1,a[i]);
        int r1=b[i-1].second+r;r1=min(r1,a[i+1]);
        b[i]={l1,r1};
    }
    vector<int> ans={le};
    pair<int,int> o={n-3,le};
    while(o.first!=(-1))
    {
        int xl=o.second-r;int xr=o.second-l;
        if(b[o.first].first>=xl) {ans.push_back(b[o.first].first);o.first--;o.second=ans.back();continue;}
        if(b[o.first].second<=xr) {ans.push_back(b[o.first].second);o.first--;o.second=ans.back();continue;}
        {ans.push_back(xl);o.first--;o.second=ans.back();continue;}
    }
    reverse(ans.begin(),ans.end());
    for(int i=0;i<ans.size()-1;++i) cout<<ans[i]<<' '<<ans[i+1]<<endl;
    return 0;
}