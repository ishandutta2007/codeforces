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

int overlap(int l1, int r1, int l2, int r2){
    debug(l1, r1, l2, r2, max(0, min(r1, r2) - max(l1, r1) + 1));
    return max(0, min(r1, r2) - max(l1, l2) + 1);
}

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vpii pairs(m);
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        x--;y--;
        pairs[i] = {x, y};
    }
    sort(pairs.begin(), pairs.end(), [&](pii a, pii b){return a.first + a.second < b.first + b.second;});
    debug(pairs);
    vi pref(m), suf(m);
    // starting at i
    vi cur_ans(n);
    for(int i = 0; i < m; i++){
        // add i to pref
        int best = 0;
        for(int j = 0; j < n; j++){
            cur_ans[j] += overlap(j, j+k-1, pairs[i].first, pairs[i].second);
            best = max(best, cur_ans[j]);
        }
        debug(i, cur_ans);
        pref[i] = best;
    }
    for(int i = 0; i < m; i++){
        // remove i from suf
        int best = 0;
        for(int j = 0; j < n; j++){
            cur_ans[j] -= overlap(j, j+k-1, pairs[i].first, pairs[i].second);
            best = max(best, cur_ans[j]);
        }
        suf[i] = best;
    }
    debug(pref, suf);
    int ans = 0;
    for(int i = 0; i < m; i++){
        ans = max(ans, suf[i] + pref[i]);
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}