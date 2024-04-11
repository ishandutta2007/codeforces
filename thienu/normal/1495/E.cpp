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

int seed = 0;
int base = 0;
const ll MOD = 1e9 + 7;

int n;

int rnd(){
    int ret = seed;
    seed = ((ll) seed * base + 233) % MOD;
    return ret;
}

void gen(vi &a, vi &t){
    int m;
    cin >> m;
    vi p(n+1);
    vi k(n+1);
    vi b(n+1);
    vi w(n+1);
    for(int i = 1; i <= m; i++){
        cin >> p[i] >> k[i] >> b[i] >> w[i];
    }
    for(int i = 1; i <= m; i++){
        seed = b[i];
        base = w[i];
        for(int j = p[i-1] + 1; j <= p[i]; j++){
            t[j-1] = (rnd() % 2) + 1;
            a[j-1] = (rnd() % k[i]) + 1;
        }
    }
}

void solve(){
    cin >> n;

    vi a(n), t(n);
    gen(a, t);
    // debug(a, t);
    
    ll s1 = 0, s2 = 0;
    for(int i = 0; i < n; i++){
        if(t[i] == 1){
            s1 += a[i];
        }
        else{
            s2 += a[i];
        }
    }

    debug(s1, s2);
    vi ans(n);
    if(s1 == s2){
        ans = a;
    }
    else if(min(s1, s2) == 0){
        ans[0] = 1;
    }
    else{
        int sat = s1 < s2 ? 1 : 2;
        int cur = 0;
        int additional = -1;
        if(sat != t[0]){
            // simulate one
            a[cur]--;
            additional = cur;
            while(t[cur] == t[0]){
                cur++;
            }
        }
        // debug(a, ans, cur);
        ll num = 0;
        for(int i = 0; i < 2 * n; i++){
            // debug(i, cur, num);
            if(t[cur] == sat){
                ans[cur] = a[cur];
                num += a[cur];
            }
            else{
                ll taken = min(num, (ll) a[cur]);
                num -= taken;
                ans[cur] = max((ll) ans[cur], taken);
            }
            cur = (cur + 1) % n;
        }
        if(additional != -1){
            ans[additional]++;
        }
        // debug(ans);
    }
    
    debug(ans);

    ll out = 1;
    for(ll i = 0; i < n; i++){
        out = out * ((((ll) ans[i] ^ ((i+1) * (i+1))) + 1) % MOD) % MOD;
    }
    cout << out << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}