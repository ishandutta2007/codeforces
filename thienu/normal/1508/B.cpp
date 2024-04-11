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

void kth_perm(int n, ll k, int start, vi &v){
    // debug(n, k, start, v);
    // debug(n);
    if(n >= 62){
        v.push_back(start);
        kth_perm(n-1, k, start + 1, v);
        return;
    }
    for(int i = 1; i <= n-1; i++){
        if(k > (1ll << n-i-1)){
            k -= (1ll << n-i-1);
        }
        else{
            for(int j = start + i - 1; j >= start; j--){
                v.push_back(j);
            }
            kth_perm(n-i, k, start + i, v);
            return;
        }
    }
    debug("base");
    for(int j = start + n - 1; j >= start; j--){
        v.push_back(j);
    }
}

void solve(){
    int n;
    ll k;
    cin >> n >> k;
    debug(n, k);

    if(n < 62 && k > (1ll << (n-1))){
        cout << -1 << endl;
        return;
    }

    vi v;
    kth_perm(n, k, 1, v);
    for(int i : v){
        cout << i << " ";
    }
    cout << endl;
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