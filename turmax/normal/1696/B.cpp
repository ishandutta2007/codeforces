#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;int a[n];vector<int> v;for(int i=0;i<n;++i) {cin>>a[i];if(a[i]) v.push_back(i);}
        if(v.empty()) {cout<<0<<'\n';continue;}
        int sz=v.size();int len=v.back()-v[0]+1;
        if(sz==len) {cout<<1<<'\n';continue;}
        cout<<2<<'\n';
    }
    return 0;
}