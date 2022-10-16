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

#define bit(x, p) ((x >> p) & 1)

int ncr_parity(int n, int r){
    for(int b = 0; b < 31; b++){
        if(bit(n-r, b) && bit(r, b)) return 0;
    }
    return 1;
}

const int B = 1 << 20;

const int LIM = 25;

void solve(){
    int n, k;
    cin >> n >> k;
    vi v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    vvi parity(n+2, vi(LIM)); // parity[i][j] => at least i xors in n-j slots
    for(int j = 0; j < LIM; j++){
        int slots = n-j;
        for(int i = slots; i >= 0; i--){
            parity[i][j] = parity[i+1][j] ^ ncr_parity(slots, i);
        }
    }
    debug(parity);

    vi bits(B);

    for(int l = 0; l < n; l++){
        ll powpow = 0;
        for(int r = l+1; r <= min(l+LIM-1, n); r++){
            if(powpow > 22) break;
            ll curbit = (ll) v[l] * (1LL << powpow);
            if(curbit > (ll) B){
                break;
            }
            debug(l, r, powpow, curbit);
            int length = r - l;
            int slots = n - length - (l > 0) - (r < n);
            int xors = k - (l > 0) - (r < n);
            debug(l, r, length, slots, xors);
            if(slots >= 0 && parity[max(xors, 0)][n-slots]){
                debug(l, r);
                bits[curbit] ^= 1;
            }
            if(r < n) powpow += v[r];
        }
    }
    bool one = false;
    for(int i = B-1; i >= 0; i--){
        if(bits[i] == 1 || one || i == 0) {
            cout << bits[i];
            one = true;
        }
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}