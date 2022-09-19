#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,p;
    cin>>n>>p;
    int a[n];
    for(int i=0;i<n;++i) cin>>a[i];
    vector <int> res;
    for(int x=0;x<=4005;++x)
    {
    //cout<<x<<" x "<<endl;
    int b[n];
    for(int i=0;i<n;++i) b[i]=min(max(0LL,n-a[i]+x),n);
    sort(b,b+n);
    //for(int i=0;i<n;++i) cout<<b[i]<<" b[i] "<<endl;
    int ans=1;
    int curr=0;
    for(int i=0;i<n;++i)
    {
        ans*=(curr+b[i]);
        ans%=p;
        curr--;
    }
    if(ans!=0)
    {
        res.push_back(x);
    }
    }
    cout<<res.size()<<endl;
    for(auto x:res)
    {
        cout<<x<<' ';
    }
    return 0;
}