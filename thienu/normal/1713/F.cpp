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

const int B = 19;
// const int B = 4;
const int N = 1 << B;

int v[N];

vi sums(vi &v){
    int n = v.size();
    vi out;
    for(int i = 0; i < n; i++){
        for(int j = 1; j < n; j++){
            v[j] ^= v[j-1];
        }
        out.push_back(v[n-1]);
    }
    return out;
}

int clz(int x){
    if(x == 0) return 32;
    else return __builtin_clz(x);
}

// works for power of 2
void solve(){
    memset(v, 0, sizeof(v));
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    // find v
    for(int i = n; i < N; i++){
        int diff = i ^ (n-1);
        int msk = (1 << (31-clz(diff))) - 1;
        int x = i & (~msk);
        int y = i & msk;
        debug(n, i, msk, x);
        for(int s = (x-1)&x; ; s = (s-1) & x){
            debug(i, s);
            v[i] ^= v[s|y];
            if(s == 0) break;
        }
    }
    debug(range(v, v+N));
    for(int b = B-1; b >= 0; b--){
        for(int i = 0; i < N; i++){
            if(((i >> b) & 1) ^ 1){
                v[i] ^= v[i ^ (1 << b)];
            }
        }
    }
    debug(range(v, v+N));
    for(int i = N-n; i < N; i++) cout << v[i] << ' ';
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}