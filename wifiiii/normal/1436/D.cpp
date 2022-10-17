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
typedef pair<int,int> pii;

const int maxn = 200005;
vector<int> g[maxn];
int a[maxn];
ll sz[maxn],tot[maxn];
ll mid;
void dfs(int u) {
    sz[u]=1,tot[u]=a[u];
    for(int v:g[u]) {
        dfs(v);
        sz[u]+=sz[v];
        tot[u]+=tot[v];
    }
}
const ll inf = 1e15;
ll chk(int u) {
    if(sz[u] == 1) {
        if(mid < tot[u]) return -1;
        return mid - tot[u];
    }
    ll res = -a[u];
    for(int v:g[u]) {
        ll tmp = chk(v);
        if(tmp == -1) return -1;
        res += tmp;
        res = min(res, inf);
    }
    if(res >= 0) return res;
    return -1;
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i=2;i<=n;++i) {
        int x;
        cin>>x;
        g[x].push_back(i);
    }
    for(int i=1;i<=n;++i) cin>>a[i];
    dfs(1);
    ll lo=0,hi=1e15;
    while(lo<hi) {
        mid=(lo+hi)/2;
        if(chk(1)!=-1) hi=mid;
        else lo=mid+1;
    }
    cout<<lo<<endl;
}