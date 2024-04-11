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

const int MAXC = 1000005;
vi phi(MAXC);

ll binexp(ll a, ll b, ll mod){
    ll ans = 1;
    while(b){
        if(b & 1){
            ans = (ans * a) % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

ll inverse(ll x, ll mod){
    return binexp(x % mod, phi[mod] - 1, mod);
}

void solve(){
    for(int i = 0; i < MAXC; i++){
        phi[i] = i;
    }
    for(int i = 2; i < MAXC; i++){
        if(phi[i] == i){
            for(int j = i; j < MAXC; j += i){
                phi[j] -= phi[j] / i;
            }
        }
    }

    int n, m;
    ll k;
    cin >> n >> m >> k;
    vi a(n);
    vi b(m);
    vi aidx(MAXC, -1);
    vi bidx(MAXC, -1);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        aidx[a[i]] = i;
    }
    for(int i = 0; i < m; i++){
        cin >> b[i];
        bidx[b[i]] = i;
    }
    ll cycle_length = (ll) n * m / __gcd(n, m);
    vll same;
    for(int i = 0; i < MAXC; i++){
        if(aidx[i] != -1 && bidx[i] != -1){
            if(aidx[i] % __gcd(n, m) == bidx[i] % __gcd(n, m)){
                ll aa = aidx[i] / __gcd(n, m);
                ll bb = bidx[i] / __gcd(n, m);
                ll mm = m / __gcd(n, m);
                ll nn = n / __gcd(n, m);
                debug(i, aa, bb, nn, mm);
                ll t = (aa * mm * inverse(mm, nn) + bb * nn * inverse(nn, mm)) % (nn * mm / __gcd(nn, mm));
                debug(t);
                same.push_back(t * __gcd(n, m) + aidx[i] % __gcd(n, m));
            }
        }
    }
    sort(same.begin(), same.end());
    debug(same);
    ll cycles = (k - 1) / (cycle_length - same.size());
    // k %= (cycle_length - same.size());
    k = k - cycles * (cycle_length - same.size());
    debug(k, cycle_length - same.size());
    ll start = k;
    ll ans = start;
    auto it = same.begin();
    while(it != same.end() && *it < start){
        ans--;
        it++;
    }
    while(ans < k){
        debug(start, ans);
        start++;
        ans++;
        while(it != same.end() && *it < start){
            ans--;
            it++;
        }
    }
    cout << cycles * cycle_length + start << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}