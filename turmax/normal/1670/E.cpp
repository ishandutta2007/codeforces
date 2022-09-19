#pragma GCC optimize("O3","Ofast","unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=(1<<18)+5;
vector<int> a[maxn];bool used[maxn];int corn[maxn];
void dfs(int x)
{
    used[x]=true;
    for(int v:a[x]) {if(!used[v]) {corn[v]=corn[x]+1;dfs(v);}}
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int k;cin>>k;int n=(1<<k);
        for(int i=0;i<n;++i) {a[i].clear();used[i]=false;corn[i]=0;}
        vector<pair<int,int> > b;
        for(int i=0;i<n-1;++i) {int x,y;cin>>x>>y;--x;--y;b.push_back({x,y});a[x].push_back(y);a[y].push_back(x);}
        dfs(0);cout<<1<<'\n';
        for(int i=0;i<n;++i)
        {
            if(i==0) {cout<<n<<' ';}
            else {if(corn[i]%2==1) {cout<<i<<' ';} else {cout<<i+n<<' ';}}
        }
        cout<<'\n';
        for(auto [x,y]:b)
        {
            if(corn[x]>corn[y]) swap(x,y);
            if(corn[x]%2==0) cout<<(n+y)<<' ';
            else cout<<y<<' ';
        }
        cout<<'\n';
    }
    return 0;
}