#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=3e5+5;
vector<int> a[maxn];int deq[maxn];int w[maxn];bool ok[maxn];bool used[maxn];int corn[maxn];
void dfs(int x)
{
    used[x]=true;
    for(int v:a[x]) if(!used[v]) {corn[v]=corn[x]+w[v];dfs(v);}
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;for(int i=0;i<n;++i) {a[i].clear();deq[i]=0;ok[i]=1;used[i]=false;corn[i]=0;}
        for(int i=0;i<n-1;++i) {int x,y;cin>>x>>y;--x;--y;++deq[x];++deq[y];a[x].push_back(y);a[y].push_back(x);}
        for(int i=0;i<n;++i) w[i]=1;
        if(n==2) {cout<<2<<'\n';continue;}
        for(int i=0;i<n;++i) w[i]=deq[i]-1;
        corn[0]=w[0];dfs(0);
        int pos=max_element(corn,corn+n)-corn;
        for(int i=0;i<n;++i) used[i]=false;
        corn[pos]=w[pos];dfs(pos);
        cout<<*max_element(corn,corn+n)+2<<'\n';
    }
    return 0;
}