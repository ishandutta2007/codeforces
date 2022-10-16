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

// kactl
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

ll MOD = 1000000007; // faster if const

ll modpow(ll b, ll e) {
    ll ans = 1;
    for (; e; b = b * b % MOD, e /= 2)
        if (e & 1) ans = ans * b % MOD;
    return ans;
}

int matInv(vector<vector<ll>>& A) {
    int n = sz(A); vi col(n);
    vector<vector<ll>> tmp(n, vector<ll>(n));
    rep(i,0,n) tmp[i][i] = 1, col[i] = i;

    rep(i,0,n) {
        int r = i, c = i;
        rep(j,i,n) rep(k,i,n) if (A[j][k]) {
            r = j; c = k; goto found;
        }
        return i;
found:
        A[i].swap(A[r]); tmp[i].swap(tmp[r]);
        rep(j,0,n) swap(A[j][i], A[j][c]), swap(tmp[j][i], tmp[j][c]);
        swap(col[i], col[c]);
        ll v = modpow(A[i][i], MOD - 2);
        rep(j,i+1,n) {
            ll f = A[j][i] * v % MOD;
            A[j][i] = 0;
            rep(k,i+1,n) A[j][k] = (A[j][k] - f*A[i][k]) % MOD;
            rep(k,0,n) tmp[j][k] = (tmp[j][k] - f*tmp[i][k]) % MOD;
        }
        rep(j,i+1,n) A[i][j] = A[i][j] * v % MOD;
        rep(j,0,n) tmp[i][j] = tmp[i][j] * v % MOD;
        A[i][i] = 1;
    }

    for (int i = n-1; i > 0; --i) rep(j,0,i) {
        ll v = A[j][i];
        rep(k,0,n) tmp[j][k] = (tmp[j][k] - v*tmp[i][k]) % MOD;
    }

    rep(i,0,n) rep(j,0,n)
        A[col[i]][col[j]] = tmp[i][j] % MOD + (tmp[i][j] < 0 ? MOD : 0);
    return n;
}


ll mul(ll a, ll b){
    return a * b % MOD;
}

ll add(ll a, ll b){
    return (a + b) % MOD;
}

vvll matmul(vvll &a, vvll &b){
    int x = a.size();
    int y = b.size();
    int z = b[0].size();
    vvll out(x, vll(z));
    for(int i = 0; i < x; i++){
        for(int j = 0; j < z; j++){
            for(int k = 0; k < y; k++){
                out[i][j] = add(out[i][j], mul(a[i][k], b[k][j]));
            }
        }
    }
    return out;
}

ll euclid(ll a, ll b, ll &x, ll &y) {
	if (!b) return x = 1, y = 0, a;
	ll d = euclid(b, a % b, y, x);
	return y -= a/b * x, d;
}

ll crt(ll a, ll m, ll b, ll n) {
	if (n > m) swap(a, b), swap(m, n);
	ll x, y, g = euclid(m, n, x, y);
	assert((a - b) % g == 0); // else no solution
	x = (b - a) % n * x % n / g * m + a;
	return x < 0 ? x + m*n/g : x;
}

ll sq(ll x){
    return x * x;
}

void solve(){
    int m, k;
    cin >> m >> k;
    vvi v(k, vi(m));
    vll sum(k);
    vll square(k);

    for(int i = 0; i < k; i++){
        for(int j = 0; j < m; j++){
            cin >> v[i][j];
            sum[i] += v[i][j];
            square[i] += (ll) v[i][j] * v[i][j];
        }
    }

    debug(sum, square);

    map<ll, int> diff;
    for(int i = 0; i < k-1; i++){
        diff[sum[i+1]-sum[i]]++;
    }
    ll d, num=0;
    for(auto p : diff){
        if(p.second > num){
            num = p.second;
            d = p.first;
        }
    }
    debug(num, d);

    map<ll, int> inter;
    for(int i = 0; i < k; i++){
        inter[sum[i]-i*d]++;
    }
    ll a; num=0;
    for(auto p : inter){
        if(p.second > num){
            num = p.second;
            a = p.first;
        }
    }
    debug(num, a);

    int wrong_time;
    ll delta;
    for(int i = 0; i < k; i++){
        if(sum[i] != a + d * i){
            wrong_time = i;
            delta = a + d * i - sum[i];
        }
    }
    debug(wrong_time, delta);

    ll sda, sdd;
    if(wrong_time >= 3){
        sda = square[1] - square[0];
        sdd = square[2] + square[0] - 2 * square[1];
    }else{
        sdd = square[6] + square[4] - 2 * square[5];
        sda = square[6] - square[5] - 5 * sdd;
    }
    debug(sdd, sda);

    // ll exp_square = x[0] * wrong_time * wrong_time + x[1] * wrong_time + x[2];
    ll exp_square;

    if(wrong_time == 0){
        exp_square = square[1] - sda;
    }else{
        exp_square = square[wrong_time - 1] + sda + sdd * (wrong_time - 1);
    }

    debug(exp_square);
    ll cur_square = square[wrong_time];
    debug(cur_square);
    for(int j = 0; j < m; j++){
        ll newsq = cur_square - sq(v[wrong_time][j]) + sq(v[wrong_time][j] + delta);
        if(newsq == exp_square){
            cout << wrong_time << ' ' << v[wrong_time][j]+delta << endl;
            return;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}