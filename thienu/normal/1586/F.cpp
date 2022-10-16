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

// log_k(n)
int logk(int n, int k){
    int ans = 1;
    while(n){
        n /= k;
        ans++;
    }
    return ans;
}

vi represent(int n, int base, int digits){
    vi v(digits);
    for(int i = digits-1; i >= 0; i--){
        v[i] = n % base;
        n /= base;
    }
    return v;
}

void solve(){
    int n, k;
    cin >> n >> k;
    int colors = logk(n-1, k) - 1;
    cout << colors << endl;

    vvi repr(n);
    for(int i = 0; i < n; i++) repr[i] = represent(i, k, colors);
    debug(repr);

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            int c;
            for(int b = 0; b < n; b++){
                if(repr[i][b] != repr[j][b]){
                    c = b;
                    break;
                }
            }
            cout << c+1 << ' ';
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