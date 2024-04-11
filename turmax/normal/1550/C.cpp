#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=2e5+5;
int a[maxn];
int ans;
void go(vector <int> v)
{
    bool ok=true;
    for(int i=0;i<v.size();++i) for(int j=(i+1);j<v.size();++j) for(int k=(j+1);k<v.size();++k) ok=(ok && ((v[j]-v[i])*(v[j]-v[k]))>0);
    if(ok) ++ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        ans=0;
        int n;
        cin>>n;
        for(int i=0;i<n;++i) cin>>a[i];
        for(int i=0;i<n;++i) {vector <int> v;for(int j=0;j<min(n-i,10LL);++j) {v.push_back(a[i+j]);go(v);}}
        cout<<ans<<'\n';
    }
    return 0;
}