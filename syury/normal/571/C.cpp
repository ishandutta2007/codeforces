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

const int N = (int)2e5 + 5;

int n, m;
bool val[N];
int cnt[N];
set<int> cls[N];
set<int> where[N];
int has[N][2];
bool used[N];
vector<pii> gr[N];
vector<pii> tree[N];
set<tuple<int, int, int> > cs;

void span(int v){
    used[v] = 1;
    for(auto [u, e]: gr[v]){
        if(!used[u]){
            tree[v].emplace_back(u, e);
            tree[u].emplace_back(v, e);
            span(u);
        }
    }
}

void mark(int v){
    used[v] = 1;
    for(auto [u, e]: tree[v]){
        if(!used[u]){
            val[e] = cls[u].count(e<<1) ? 0 : 1;
            mark(u);
        }
    }
}

void restore(int v){
    sort(all(gr[v]));
    sort(all(tree[v]));
    mark(v);
    auto ptr = tree[v].begin();
    for(auto edge: gr[v]){
        while(ptr != tree[v].end() && *ptr < edge)++ptr;
        if(ptr == tree[v].end() || *ptr != edge){
            val[edge.Y] = cls[v].count(edge.Y<<1) ? 0 : 1;
            break;
        }
    }
}

void solve(){
    cin >> m >> n;
    for(int i = 0; i < m; i++){
        int k;
        cin >> k;
        vector<int> kek(k);
        for(int j = 0; j < k; j++)
            cin >> kek[j];
        sort(all(kek));
        kek.erase(unique(all(kek)), kek.end());
        k = kek.size();
        for(int j = 0; j < k; j++){
            int v = kek[j];
            v = (v < 0 ? 0 : 1) | ((abs(v) - 1)<<1);
            ++cnt[v>>1];
            ++has[v>>1][v&1];
            cls[i].insert(v);
            where[v>>1].insert(i);
        }
    }
    for(int i = 0; i < m; i++){
        bool taut = 0;
        for(int v: cls[i]){
            if((v&1) && (cls[i].count(v^1))){
                taut = 1;
                break;
            }
        }
        if(taut){
            for(int v: cls[i]){
                --cnt[v>>1];
                --has[v>>1][v&1];
                where[v>>1].erase(i);
            }
        }
    }
    for(int i = 0; i < n; i++)
        cs.emplace(cnt[i], int(has[i][0] > 0) + int(has[i][1] > 0), i);
    while(!cs.empty() && (get<0>(*cs.begin()) <= 1 || get<1>(*cs.begin()) <= 1)){
        int v = get<2>(*cs.begin());
        cs.erase(cs.begin());
        if(!cnt[v])
            continue;
        val[v] = has[v][1] > 0;
        for(auto c: where[v]){
            cls[c].erase(v<<1);
            cls[c].erase((v<<1)|1);
            for(int u1: cls[c]){
                int u = u1>>1;
                if(u == v)continue;
                where[u].erase(c);
                cs.erase(make_tuple(cnt[u], int(has[u][0] > 0) + int(has[u][1] > 0), u));
                --cnt[u];
                --has[u][u1&1];
                cs.emplace(cnt[u], int(has[u][0] > 0) + int(has[u][1] > 0), u);
            }
            cls[c].clear();
        }
        where[v].clear();
    }
    for(int v = 0; v < n; v++){
        if(!where[v].empty()){
            int l = *where[v].begin();
            int r = *(++where[v].begin());
            gr[l].emplace_back(r, v);
            gr[r].emplace_back(l, v);
        }
    }
    for(int v = 0; v < m; v++){
        if(!used[v] && gr[v].size() > 0u)
            span(v);
    }
    fill(used, used + m, false);
    for(int v = 0; v < m; v++){
        if(!used[v] && tree[v].size() != gr[v].size()){
            restore(v);
        }
    }
    for(int v = 0; v < m; v++){
        if(!gr[v].empty() && !used[v]){
            cout << "NO";
            return;
        }
    }
    cout << "YES\n";
    for(int v = 0; v < n; v++)
        cout << (int)val[v];
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