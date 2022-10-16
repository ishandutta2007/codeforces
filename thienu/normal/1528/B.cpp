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

const int MAXN = 1e6 + 5;
vi lp(MAXN);
vi pr;
vi nd(MAXN);

const int MOD = 998244353;

void precalc(){
    for (int i=2; i<MAXN; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back (i);
        }
        for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<MAXN; ++j){
            lp[i * pr[j]] = pr[j];
        }
    }
    for(int i = 1; i < MAXN; i++){
        map<int, int> div;
        int cur = i;
        while(cur > 1){
            div[lp[cur]]++;
            cur /= lp[cur];
        }
        int d = 1;
        for(auto it = div.begin(); it != div.end(); it++){
            d *= it->second + 1;
        }
        nd[i] = d;
    }
}

ll add(ll a, ll b){
    return (a + b) % MOD;
}

void solve(){
    int n;
    cin >> n;
    vll f(n+1);
    f[0] = 1;
    ll sum = 1;
    for(int i = 1; i <= n; i++){
        f[i] = add(sum, nd[i] - 1);
        sum = add(sum, f[i]);
    }
    cout << f[n] << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precalc();
    solve();
    return 0;
}