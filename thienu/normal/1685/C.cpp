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

void solve(){
    int n;
    string s;
    cin >> n >> s;
    n *= 2;
    vi layer(n+1);
    int first_negative = -1;
    int last_negative = -1;
    for(int i = 0; i < n; i++){
        layer[i+1] = layer[i] + (s[i] == '(' ? 1 : -1);
        if(layer[i+1] < 0){
            last_negative = i+1;
            if(first_negative == -1){
                first_negative = i+1;
            }
        }
    }
    debug(first_negative, last_negative);
    if(first_negative == -1){
        cout << 0 << endl;
        return;
    }
    debug(layer);
    int max_pos = max_element(layer.begin(), layer.end()) - layer.begin();
    debug(max_pos);
    int maxl = max_element(layer.begin(), layer.begin() + first_negative) - layer.begin();
    int maxr = max_element(layer.begin() + last_negative + 1, layer.end()) - layer.begin();
    if(layer[maxl] + layer[maxr] >= layer[max_pos]){
        cout << 1 << endl;
        cout << maxl + 1 << ' ' << maxr << endl;
    }else{
        cout << 2 << endl;
        cout << 1 << ' ' << max_pos << endl;
        cout << max_pos + 1 << ' ' << n << endl;
    }
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