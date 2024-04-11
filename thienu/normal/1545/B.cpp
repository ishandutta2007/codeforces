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

const ll MOD = 998244353;

ll mul(ll a, ll b){
    return a * b % MOD;
}

ll add(ll a, ll b){
    return (a + b) % MOD;
}

ll binexp(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b & 1) ans = mul(ans, a);
        a = mul(a, a);
        b >>= 1;
    }
    return ans;
}

ll inv(ll x){
    return binexp(x, MOD - 2);
}

const int N = 1e5 + 12;

ll fact[N];
ll inv_fact[N];
void precomp(){
    fact[0] = 1;
    for(int i = 1; i < N; i++){
        fact[i] = mul(fact[i-1], i);
    }
    for(int i = 0; i < N; i++){
        inv_fact[i] = inv(fact[i]);
    }
}

ll ncr(ll n, ll r){
    return mul(fact[n], mul(inv_fact[r], inv_fact[n-r]));
}

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int zeros = 0;
    int og = 0;
    int last = s[0]-'0';
    int run_cnt = 0;
    for(int i = 0; i < n; i++){
        int cur = s[i]-'0';
        if(cur != last){
            if(last == 0){
                zeros += run_cnt;
            }else{
                og += run_cnt / 2;
            }
            last = cur;
            run_cnt = 1;
        }else{
            run_cnt++;
        }
    }
    if(last == 0){
        zeros += run_cnt;
    }else{
        og += run_cnt / 2;
    }
    cout << ncr(og + zeros, og) << endl;
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