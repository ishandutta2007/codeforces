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

int a[500005], vis[500005], cnt[500005];
vector<int> g[500005];
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=m;++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;++i) cin>>a[i];
    vector<int> ord(n);
    iota(all(ord),1);
    sort(all(ord),[&](int i,int j) {return a[i]<a[j];});
    int ok = 1;
    for(int i : ord) {
        int target = a[i];
        for(int v : g[i]) {
            if(!vis[v]) continue;
            cnt[a[v]]++;
        }
        int tmp = 1;
        while(cnt[tmp]) ++tmp;
        if(tmp != target) {
            ok = 0;
            break;
        }
        for(int v : g[i]) {
            if(!vis[v]) continue;
            cnt[a[v]]--;
        }
        vis[i] = 1;
    }
    if(ok) {
        for(int i : ord) cout << i << " "; cout << endl;
    } else {
        cout << -1 << endl;
    }
}