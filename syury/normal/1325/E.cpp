//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define pb push_back
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

const int N = (int)1e6 + 6;

int lp[N];
int a[N];
int n;
int l[N], r[N];
int q[N];
int d[N];
int spred[N];
int vis[N];
vector<int> gr[N];
vector<int> good;
vector<pii> edges;
int qh = 0, qt = 0;

inline void add_edge(int v, int u){
    gr[v].push_back(edges.size());
    gr[u].push_back(edges.size());
    edges.emplace_back(v, u);
}

int cycle(int s){
    qh = qt = 0;
    q[qt++] = s;
    for(auto v: good)
        d[v] = N;
    d[s] = 0;
    while(qh < qt){
        int v = q[qh++];
        for(auto e: gr[v]){
            int u = edges[e].X == v ? edges[e].Y : edges[e].X;
            if(d[u] == N){
                d[u] = d[v] + 1;
                if(v == s)
                    spred[u] = u;
                else
                    spred[u] = spred[v];
                q[qt++] = u;
                vis[e] = s;
            }
        }
    }
    spred[0] = -1;
    int ans = N;
    for(size_t i = 0; i < edges.size(); i++){
        if(vis[i] == s)
            continue;
        int v, u;
        tie(v, u) = edges[i];
        if(spred[v] != spred[u]){
            ans = min(ans, 1 + d[v] + d[u]);
        }
    }
    return ans;

}

void solve(){
    fill(vis, vis + N, -1);
    good = {0};
    for(int i = 2; i < N; i++){
        if(lp[i])
            continue;
        for(int j = i; j < N; j += i){
            lp[j] = lp[j] ? lp[j] : i;
        }
    }
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", a + i);
    for(int i = 0; i < n; i++){
        int j = a[i];
        while(j > 1){
            int pr = 0;
            int p = lp[j];
            while(j%p == 0){
                j /= p;
                pr ^= 1;
            }
            if(pr)
            {if(l[i])r[i] = p; else l[i] = p;}
        }
        good.push_back(l[i]);
        good.push_back(r[i]);
        if(!l[i]){
            cout << "1\n";
            return;
        }
        if(r[i]){
            add_edge(l[i], r[i]);
        }
    }
    sort(all(good));
    good.erase(unique(all(good)), good.end());
    int ans = N;
    for(int p = 2; p * p < N; p++){
        if(lp[p] != p)
            continue;
        ans = min(ans, cycle(p));
    }
    for(int i = 0; i < n; i++)
        if(!r[i])
            add_edge(l[i], 0);
    ans = min(ans, cycle(0));
    if(ans > n)
        ans = -1;
    cout << ans << endl;
}

signed main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    while(T--)
        solve();
    return 0;
}