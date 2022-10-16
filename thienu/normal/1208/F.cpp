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

const int B = 21;
// const int B = 4;

pii upd(pii a, pii b){
    if(a.first > b.first){
        return {a.first, max(a.second, b.first)};
    }else{
        return {b.first, max(b.second, a.first)};
    }
}

void solve(){
    int n;
    cin >> n;
    vi v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    vpii lst(1<<B, {-1, -1});
    for(int i = 0; i < n; i++){
        lst[v[i]] = upd(lst[v[i]], {i, -1});
    }
    debug(lst);

    for(int b = 0; b < B; b++){
        for(int i = 0; i < (1<<B); i++){
            if((i>>b)&1){
                lst[i^(1<<b)] = upd(lst[i], lst[i^(1<<b)]);
            }
        }
    }
    debug(lst);

    int ans = 0;
    for(int i = 0; i < n-2; i++){
        int cur = 0;
        for(int b = B-1; b >= 0; b--){
            if((v[i]>>b)&1) continue;
            int cand = cur | (1<<b);
            if(lst[cand].second > i){
                cur = cand;
            }
        }
        ans = max(ans, cur | v[i]);
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}