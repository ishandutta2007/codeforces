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

vi fib;
void precomp(){
    int a = 1;
    int b = 2;
    fib.push_back(1);
    while(b <= 1e9){
        fib.push_back(b);
        b = a + b;
        a = b - a;
    }
    debug(fib, fib.size());
}


bool check(vi &occ){
    bool started = false;
    for(int i = fib.size() - 1; i >= 0; i--){
        if(occ[i] > 1){
            return false;
        }else if(occ[i] == 1){
            started = true;
        }else if(occ[i] == 0 && started){
            return false;
        }
    }
    return true;

}

bool upd(vi &occ, int x, int d){
    bool good = true;
    for(int j = fib.size() - 1; j >= 0; j--){
        if(j == 0 && x == 1) good = false;
        if(x >= fib[j]){
            occ[j] += d;
            x -= fib[j];
        }
    }
    return good;
}

void solve(){
    int n;
    cin >> n;
    vi v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    

    vi occ(fib.size());

    for(int i = 0; i < n; i++){
        int x = v[i];
        upd(occ, x, 1);
    }
    debug(occ);

    for(int j = 0; j < n; j++){
        upd(occ, v[j], -1);
        v[j]--;
        bool good = upd(occ, v[j], 1);
        if(!good){
            upd(occ, v[j], -1);
            v[j]++;
            upd(occ, v[j], 1);
            continue;
        }
        bool res = check(occ);
        if(res){
            cout << "YES" << endl;
            return;
        }
        upd(occ, v[j], -1);
        v[j]++;
        upd(occ, v[j], 1);
    }
    cout << "NO" << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precomp();
    int tc;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}