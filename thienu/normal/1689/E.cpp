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

const int B = 31;

int find_par(vi &par, int a){
    if(a == par[a]) return a;
    return par[a] = find_par(par, par[a]);
}

void merge(vi &par, int a, int b){
    a = find_par(par, a);
    b = find_par(par, b);
    par[a] = b;
}

bool connected(vi &v, int n){
    vi par(B);
    vi vis;
    iota(par.begin(), par.end(), 0);
    for(int i = 0; i < n; i++){
        if(v[i] == 0) return false;
        vi bits;
        for(int b = 0; b < B; b++){
            if((v[i] >> b) & 1){
                vis.push_back(b);
                bits.push_back(b);
            }
        }
        for(int j = 1; j < bits.size(); j++){
            merge(par, bits[0], bits[j]);
        }
    }
    debug(par, vis);
    for(int i = 1; i < vis.size(); i++){
        if(find_par(par, vis[0]) != find_par(par, vis[i])){
            return false;
        }
    }
    return true;
}

void answer(int ans, vi &v){
    cout << ans << endl;
    for(int i : v){
        cout << i << ' ';
    }
    cout << endl;
}

void solve(){
    int n;
    cin >> n;
    int ans = 0;
    vi v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        if(v[i] == 0){
            v[i]++;
            ans++;
        }
    }

    if(connected(v, n)){
        answer(ans, v);
        return;
    }

    for(int i = 0; i < n; i++){
        v[i]++;
        if(connected(v, n)){
            answer(ans+1, v);
            return;
        }
        v[i] -= 2;
        if(connected(v, n)){
            answer(ans+1, v);
            return;
        }
        v[i]++;
    }

    int hi_bit = 0;
    vi idxs;
    for(int i = 0; i < n; i++){
        debug(i, __builtin_ctz(v[i]));
        if(__builtin_ctz(v[i]) > hi_bit){
            hi_bit = __builtin_ctz(v[i]);
            idxs.clear();
        }
        if(__builtin_ctz(v[i]) == hi_bit){
            idxs.push_back(i);
        }
    }
    debug(hi_bit, idxs);
    assert(idxs.size() >= 2);
    v[idxs[0]]--;
    v[idxs[1]]++;

    answer(ans+2, v);
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