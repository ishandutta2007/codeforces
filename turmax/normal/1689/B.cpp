#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;int a[n+1];a[n]=(-1);for(int i=0;i<n;++i) {cin>>a[i];--a[i];}
        int ans[n];set <int> o;for(int i=0;i<n;++i) o.insert(i);
        if(n==1) {cout<<(-1)<<'\n';continue;}
        for(int i=0;i<n;++i)
        {
            if(o.count(a[i])) {o.erase(a[i]);ans[i]=(*o.begin());o.erase(ans[i]);o.insert(a[i]);}
            else if(o.size()>2 || o.size()==1) {ans[i]=(*o.begin());o.erase(o.begin());}
            else if(o.count(a[i])) {o.erase(a[i]);ans[i]=(*o.begin());o.erase(ans[i]);o.insert(a[i]);}
            else if(o.count(a[i+1])) {ans[i]=a[i+1];o.erase(a[i+1]);}
            else {ans[i]=(*o.begin());o.erase(o.begin());}
        }
        for(auto h:ans) cout<<h+1<<' ';
        cout<<'\n';
    }
    return 0;
}