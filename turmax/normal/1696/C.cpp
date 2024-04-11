#include <bits/stdc++.h>

using namespace std;
#define int long long
int f(int x,int m)
{
    while(x%m==0) x/=m;
    return x;
}
vector<pair<int,int> > go(vector<int> a,int m)
{
    int n=a.size();vector<pair<int,int> > ans;
    int cur=0;int sum=0;
    for(int i=0;i<n;++i)
    {
        if(i!=0 && f(a[i],m)!=f(a[i-1],m))
        {
            ans.push_back({f(a[i],m),sum});cur=1;sum=a[i];
        }
        else
        {
            ++cur;sum+=a[i];
        }
    }
    ans.push_back({f(a.back(),m),sum});
    return ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
       int n,m;cin>>n>>m;vector<int> a(n);for(int i=0;i<n;++i) cin>>a[i]; vector<pair<int,int> > v1=go(a,m);
       cin>>n;vector<int> b(n);for(int i=0;i<n;++i) cin>>b[i]; vector<pair<int,int> > v2=go(b,m);
       puts(v1==v2 ? "Yes" : "No");
    }
    return 0;
}