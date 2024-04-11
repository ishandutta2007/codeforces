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

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef DEBUG
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

const int INF = 1e9 + 7;
// kactl
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
struct Node {
    Node *l = 0, *r = 0;
    int lo, hi, madd = -INF, val = -INF, idx = -1, midx = -1;
    Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -INF
    Node(vi& v, int lo, int hi) : lo(lo), hi(hi) {
        if (lo + 1 < hi) {
            int mid = lo + (hi - lo)/2;
            l = new Node(v, lo, mid); r = new Node(v, mid, hi);
            if(l->val > r->val){
                val = l->val;
                idx = l->idx;
            }else{
                val = r->val;
                idx = r->idx;
            }
        }
        else val = v[lo];
    }
    pii query(int L, int R) {
        if (R <= lo || hi <= L) return {-INF, -1};
        if (L <= lo && hi <= R) return {val, idx};
        push();
        return max(l->query(L, R), r->query(L, R));
    }
    void add(int L, int R, int x, int id) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            if(madd < x){
                madd = val = x;
                midx = idx = id;
            }
        }
        else {
            push(), l->add(L, R, x, id), r->add(L, R, x, id);
            if(l->val > r->val){
                val = l->val;
                idx = l->idx;
            }else{
                val = r->val;
                idx = r->idx;
            }
        }
    }
    void push() {
        if (!l) {
            int mid = lo + (hi - lo)/2;
            l = new Node(lo, mid); r = new Node(mid, hi);
        }
        if (madd != -INF)
            l->add(lo,hi,madd, midx), r->add(lo,hi,madd, midx), madd = -INF, midx = -1;
    }
};
void solve(){
    int n, m;
    cin >> n >> m;
    vector<pair<int, pii>> q;
    vi values;
    for(int i = 0; i < m; i++){
        int x, l, r;
        cin >> x >> l >> r;
        q.push_back({x, {l, r}});
        values.push_back(l);
        values.push_back(r);
    }
    sort(values.begin(), values.end());
    map<int, int> ma;
    for(int i = 0; i < values.size(); i++){
        ma[values[i]] = i;
    }
    vector<vpii> v(n);
    for(int i = 0; i < m; i++){
        v[q[i].first-1].push_back({ma[q[i].second.first], ma[q[i].second.second] + 1});
    }
    Node st(0, values.size());
    debug(v);
    vi dp(n), par(n);
    for(int i = 0; i < n; i++){
        pii best = {-1, -1};
        for(pii p : v[i]){
            best = max(best, st.query(p.first, p.second));
        }
        debug(best);
        debug(st.val);
        if(best.first == -1){
            dp[i] = 1;
            par[i] = -1;
        }else{
            dp[i] = best.first + 1;
            par[i] = best.second;
        }
        for(pii p : v[i]){
            st.add(p.first, p.second, dp[i], i);
        }
    }
    debug(dp, par);
    int cur = max_element(dp.begin(), dp.end()) - dp.begin();
    debug(cur);
    cout << n - dp[cur] << endl;
    vi in(n);
    while(cur != -1){
        in[cur] = 1;
        cur = par[cur];
    }
    for(int i = 0; i < n; i++){
        if(in[i] == 0) cout << i+1 << ' ';
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}