#include <bits/stdc++.h>

using namespace std;

#define u_map unordered_map
#define u_set unordered_set
#define u_multiset unordered_multiset
#define int long long
using ll = long long;
using vvi = vector<vector<int>>;
using vi = vector<int>;
using vvll = vector<vector<long long>>;
using vll = vector<long long>;
using vd = vector<double>;
using vvd = vector<vector<double>>;
using pii = pair<int, int>;
using vpii = vector<pair<int, int>>;
#undef int

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
#define int long long
void dfs(int v, vi &score, vi &parent, vvi &child, vi &tot, vi &lo, vpii &ans){
    debug(v, tot);
    if(child[v].size() == 0){
        ans[v] = make_pair(tot[v] * lo[v], tot[v] * (lo[v] + 1));
        return;
    }

    debug(v, lo[v]);

    int paths = lo[v];
    int nc = child[v].size();
    int child_lo = paths / nc;
    int lo_ans = 0;
    vi child_hi;
    for(int u : child[v]){
        lo[u] = child_lo;
        tot[u] = tot[v] + score[u];
        dfs(u, score, parent, child, tot, lo, ans);
        lo_ans += ans[u].first;
        child_hi.push_back(ans[u].second - ans[u].first);
    }
    sort(child_hi.begin(), child_hi.end());
    int residue = paths - nc * child_lo;
    for(int i = 0; i < residue; i++){
        lo_ans += child_hi[nc - i - 1];
    }
    int hi_ans = lo_ans + child_hi[nc - residue - 1];
    ans[v] = make_pair(lo_ans, hi_ans);
}

void solve(){
    int n, k;
    cin >> n >> k;
    vi score(n);
    vi parent(n, -1);
    vvi child(n);
    for(int i = 1; i < n; i++){
        int x;
        cin >> x;
        x--;
        parent[i] = x;
        child[x].push_back(i);
    }
    debug(child);
    for(int i = 0; i < n; i++) cin >> score[i];

    vi tot(n);
    tot[0] = score[0];
    vi lo(n);
    lo[0] = k;
    vpii ans(n);

    debug(tot);

    dfs(0, score, parent, child, tot, lo, ans);

    cout << ans[0].first << endl;
}
#undef int
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