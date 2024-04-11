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
#define int long long
const int B = 350;

// kactl
struct Tree {
    typedef ll T;
    static constexpr T unit = -4e18;
    T f(T a, T b) { return max(a, b); } // (any associative fn)
    vector<T> s; int n;
    Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
    void update(int pos, T val) {
        for (s[pos += n] = val; pos /= 2;)
            s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
    }
    T query(int b, int e) { // query [b, e)
        T ra = unit, rb = unit;
        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b % 2) ra = f(ra, s[b++]);
            if (e % 2) rb = f(s[--e], rb);
        }
        return f(ra, rb);
    }
};

void solve(){
    int n, q;
    cin >> n >> q;
    vi v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v[i] -= x;
    }
    debug(v);
    vll delta(n+1);
    for(int i = 0; i < n; i++){
        delta[i+1] = delta[i] + v[i];
    }
    debug(delta);
    Tree st(n+1);
    for(int i = 0; i < n+1; i++){
        st.update(i, delta[i]);
    }
    vector<pair<pii, int>> pairs;
    vector<pair<pii, int>> rpairs;
    stack<pii> s;
    for(int i = 0; i < n; i++){
        if(v[i] > 0){
            s.push({i, v[i]});
        }
        else if(v[i] < 0){
            int x = -v[i];
            while(!s.empty() && x > 0){
                pii p = s.top();
                s.pop();
                if(p.second <= x){
                    x -= p.second;
                    pairs.push_back({{p.first, i}, p.second});
                    rpairs.push_back({{i, p.first}, p.second});
                }else{
                    pairs.push_back({{p.first, i}, x});
                    rpairs.push_back({{i, p.first}, x});
                    s.push({p.first, p.second - x});
                    x = 0;
                }
            }
        }
    }
    debug(pairs);
    sort(pairs.begin(), pairs.end());
    sort(rpairs.begin(), rpairs.end(), greater<pair<pii, int>>());
    debug(pairs, rpairs);

    // other, prefix
    vector<vector<pair<int, ll>>> left(n);
    for(int i = 0; i < n; i++){
        left[i].push_back({i, 0});
    }
    for(auto p : pairs){
        ll lst = left[p.first.first].empty() ? 0LL : prev(left[p.first.first].end())->second;
        left[p.first.first].push_back({p.first.second, p.second + lst});
    }
    debug(left);
    // other, suffix
    vector<vector<pair<int, ll>>> right(n);
    for(int i = 0; i < n; i++){
        right[i].push_back({i, 0});
    }
    for(auto p : rpairs){
        ll lst = right[p.first.first].empty() ? 0LL : prev(right[p.first.first].end())->second;
        right[p.first.first].push_back({p.first.second, p.second + lst});
    }
    debug(right);

    vector<vector<pair<pii, int>>> queries((n-1)/B+1);
    for(int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r;
        l--;
        queries[l/B].push_back({{l, r}, i});
    }
    for(auto &x : queries){
        sort(x.begin(), x.end(), [](pair<pii, int> x, pair<pii, int> y){return x.first.second < y.first.second || x.first.second == y.first.second && x < y;});
    }
    debug(queries);
    
    int l = 0, r = 0;
    int lo, hi;
    ll free = 0;
    ll pos_sum = 0;
    vll ans(q);

    auto move_l_left = [&](){
        l--;
        if(v[l] > 0) pos_sum += v[l];
        auto it = prev(lower_bound(left[l].begin(), left[l].end(), make_pair(r, 0LL)));
        free += it->second;
        debug("lleft", free);
    };
    auto move_l_right = [&](){
        if(v[l] > 0) pos_sum -= v[l];
        auto it = prev(lower_bound(left[l].begin(), left[l].end(), make_pair(r, 0LL)));
        free -= it->second;
        l++;
        debug("lright", free);
    };
    auto move_r_left = [&](){
        r--;
        if(v[r] > 0) pos_sum -= v[r];
        auto it = prev(upper_bound(right[r].begin(), right[r].end(), make_pair(l, 0LL), greater<pair<int, ll>>()));
        free -= it->second;
        debug("rleft", free);
    };
    auto move_r_right = [&](){
        if(v[r] > 0) pos_sum += v[r];
        debug(right[r]);
        auto it = prev(upper_bound(right[r].begin(), right[r].end(), make_pair(l, 0LL), greater<pair<int, ll>>()));
        free += it->second;
        r++;
        debug("rright", free);
    };
    for(int block = 0; block < queries.size(); block++){
        for(auto qu : queries[block]){
            pii p = qu.first;
            int idx = qu.second;
            debug(p);
            if(delta[p.first] != delta[p.second] || st.query(p.first, p.second) > delta[p.first]){
                ans[idx] = -1;
                continue;
            }

            lo = p.first, hi = p.second;
            if(lo < l){
                while(lo < l){
                    move_l_left();
                }
                while(hi < r){
                    move_r_left();
                }
                while(hi > r){
                    move_r_right();
                }
            }else{
                while(hi < r){
                    move_r_left();
                }
                while(hi > r){
                    move_r_right();
                }
                while(lo > l){
                    move_l_right();
                }
            }
            debug(p, free, pos_sum);
            ans[idx] = pos_sum - free;
        }
    }
    for(int i : ans){
        cout << i << '\n';
    }
}
#undef int
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}