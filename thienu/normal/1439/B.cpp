#include <bits/stdc++.h>

using namespace std;

#define u_map unordered_map
#define u_set unordered_set
#define u_multiset unordered_multiset

using ll = long long;
using vvi = vector<vector<int>>;
using vi = vector<int>;
using vvll = vector<vector<long long>>;
using vll = vector<long long>;
using vd = vector<double>;
using vvd = vector<vector<double>>;
using pii = pair<int, int>;
using vpii = vector<pair<int, int>>;

template<typename C> struct rge{C l, r;};
template<typename C> rge<C> range(C i, C j) { return rge<C>{i, j}; }
template<typename C> ostream& operator<<(ostream &os, rge<C> &r) { os << '{'; for(auto it = r.l; it != r.r; it++) os << "," + (it == r.l) << *it; os << '}'; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '{' << p.first << "," << p.second << '}'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ","; return os << '}'; }
void dbg_out() { cerr << ']' << endl; }
template<typename A> void dbg_out(A H) { cerr << H; dbg_out(); }
template<typename A, typename B, typename... C> void dbg_out(A H, B G, C... T) { cerr << H << ","; dbg_out(G, T...); }
#ifdef DEBUG
#define debug(...) cerr << "[" << #__VA_ARGS__ << "] = [", dbg_out(__VA_ARGS__)
#else
#define debug(...)
#endif

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

ll isqrt(ll n){
    ll x = n;
    ll y = (x + 1) >> 1;
    while(y < x){
        x = y;
        y = (x + n / x) >> 1;
    }
    return x;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int C = rng();

struct chash{
    int operator()(pii p) const {
        int a = (p.first ^ C) * 0x238B3F2C;
        int b = (p.second * 0x13BF93B1) ^ C;
        return a ^ (b << 4) ^ C;
    }
};

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    gp_hash_table<pii, int, chash> edges;
    vector<set<int>> adj(n);
    vi deg(n);
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        x--;y--;
        edges[{x, y}] = 1;
        edges[{y, x}] = 1;
        adj[x].insert(y);
        adj[y].insert(x);
        deg[x]++;
        deg[y]++;
    }
    if(k > isqrt(2*m)+5){
        cout << -1 << endl;
        return;
    }


    set<pii> nodes;
    for(int i = 0; i < n; i++){
        nodes.insert({deg[i], i});
    }

    while(!nodes.empty()){
        debug(nodes);
        int degree, idx;
        tie(degree, idx) = *nodes.begin();
        if(degree >= k){
            cout << 1 << ' ' << nodes.size() << endl;
            for(pii p : nodes){
                cout << p.second+1 << ' ';
            }
            cout << endl;
            return;
        }else if(degree == k-1){
            // check for clique
            vi cand;
            for(int i : adj[idx]){
                cand.push_back(i);
            }
            bool ok = true;
            for(int i = 0; i < cand.size(); i++){
                for(int j = i+1; j < cand.size(); j++){
                    if(edges.find({cand[i], cand[j]}) == edges.end()){
                        ok = false;
                        goto done;
                    }
                }
            }
            cand.push_back(idx);
            done:;
            if(ok){
                cout << 2 << endl;
                for(int i : cand){
                    cout << i+1 << ' ';
                }
                cout << endl;
                return;
            }
        }
        // delete node
        nodes.erase(nodes.begin());
        debug(idx, degree, adj[idx], nodes);
        for(int i : adj[idx]){
            adj[i].erase(idx);
            nodes.erase({deg[i], i});
            deg[i]--;
            nodes.insert({deg[i], i});
        }
    }
    cout << -1 << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}