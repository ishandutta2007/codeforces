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

const int maxn = 100005;
vector<int> g[maxn];
unordered_map<int,int> mp[maxn];
int deg[maxn], deg2[maxn], vis[maxn], vis2[maxn];
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m, k;
        cin >> n >> m >> k;
        for(int i=1;i<=n;++i) mp[i].clear(), g[i].clear(), deg2[i]=vis2[i]=0;
        for(int i=1;i<=m;++i) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
            mp[u][v]=mp[v][u]=1;
            deg2[u]++;deg2[v]++;
        }
        if(1ll*k*(k-1)/2 > m) {
            cout << -1 << endl;
            continue;
        }
        // find at least k neighbors
        {
            for(int i=1;i<=n;++i) deg[i]=deg2[i],vis[i]=0;
            queue<int> q;
            for(int i=1;i<=n;++i) {
                if(deg[i]<k) q.push(i), vis[i]=1;
            }
            while(!q.empty()) {
                int cur=q.front();q.pop();
                for(int v:g[cur]) {
                    if(vis[v]) continue;
                    if(--deg[v]<k) {
                        q.push(v);
                        vis[v]=1;
                    }
                }
            }
            int cnt=0;
            for(int i=1;i<=n;++i) if(!vis[i]) ++cnt;
            if(cnt) {
                cout << 1 << " " << cnt << endl;
                for(int i=1;i<=n;++i) if(!vis[i]) cout<<i<<" ";
                cout << endl;
                continue;
            }
        }

        // find k-clique
        {
            for(int i=1;i<=n;++i) deg[i]=deg2[i],vis[i]=0;
            queue<int> q;
            for(int i=1;i<=n;++i) {
                if(deg[i]<k-1) q.push(i), vis[i]=1;
            }
            while(!q.empty()) {
                int cur=q.front();q.pop();
                for(int v:g[cur]) {
                    if(vis[v]) continue;
                    if(--deg[v]<k-1) {
                        q.push(v);
                        vis[v]=1;
                    }
                }
            }
            for(int i=1;i<=n;++i) if(!vis[i] && deg[i]==k-1) q.push(i), vis2[i]=1;
//            ii cout << vis[i] << " " << deg[i] << endl;
            int ok = 0;
            while(!q.empty()) {
                int u=q.front();q.pop();
                vector<int> vs{u};
                for(int v : g[u]) {
                    if(vis[v]) continue;
                    vs.push_back(v);
                }
//                cout << u << ": " << vs.size() << endl;
                if(vs.size() == k) {
                    int okk = 1;
                    for(int i=0;i<vs.size();++i) {
                        for(int j=i+1;j<vs.size();++j) {
                            if(!mp[vs[i]].count(vs[j])) {
                                okk = 0;
                                break;
                            }
                        }
                        if(!okk) break;
                    }
                    if(okk) {
                        ok = 1;
                        cout << 2 << endl;
                        sort(vs.begin(), vs.end());
                        for(int j : vs) {
                            cout << j << " ";
                        }
                        cout << endl;
                        break;
                    }
                }
                vis[u]=1;
                for(int v:g[u]) {
                    --deg[v];
                    if(vis[v] || vis2[v]) continue;
                    if(deg[v]==k-1) {
                        q.push(v);
                        vis2[v]=1;
                    }
                }
            }
            if(ok) continue;
        }
        cout << -1 << endl;
    }
}