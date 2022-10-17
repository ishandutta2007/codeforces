#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 mrand(42);
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define al(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define asdd cout<<"okok"<<endl;
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pr(v) for(auto i:v) cout<<i<<" ";cout<<endl;
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back
#define PS string qqwwee;cin>>qqwwee;
typedef pair<int, int> pii;

vector<int> g[200005];
int dfs(int u, int fa, int k) {
    if(g[u].size() == 1 && fa == g[u][0]) {
        return 0;
    }
    vector<int> a;
    for(int v : g[u]) {
        if(v == fa) continue;
        int tmp = dfs(v, u, k);
        assert(tmp <= k);
        if(tmp == -1) return -1;
        a.push_back(tmp);
    }
    sort(a.begin(), a.end());
    if(a.size() == 1) {
        if(a[0] + 1 > k) return -1;
        return a[0] + 1;
    }
    if(a[0] + 2 > k) return -1;
    if(a.back() + 2 <= k) return a[0] + 1;
    if(a[a.size()-2] + 2 > k) return -1;
    if(a.back() + 1 > k) return -1;
    return a.back() + 1;
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        for(int i=1;i<=n;++i) g[i].clear();
        for(int i=1;i<n;++i) {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int lo=1,hi=n;
        while(lo<hi) {
            int mid=(lo+hi)/2;
            if(dfs(1,0,mid)!=-1) hi=mid;
            else lo=mid+1;
        }
        cout<<lo<<endl;
    }
}