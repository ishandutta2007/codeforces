#include <bits/stdc++.h>
#include <bits/extc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define pb(a) push_back(a)
#define eb(a) emplace_back(a)
#define pf(a) push_front(a)
#define ef(a) emplace_front(a)
#define pob pop_back()
#define pof pop_front()
#define mp(a, b) make_pair(a, b)
//#define F first
#define S second
#define mt make_tuple
#define gt(t, i) get<i>(t)
#define tomax(a, b) ((a) = max((a), (b)))
#define tomin(a, b) ((a) = min((a), (b)))
#define topos(a) ((a) = (((a) % MOD + MOD) % MOD))
#define uni(a) a.resize(unique(iter(a)) - a.begin())
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<ld, ld>;
using tiii = tuple<int, int, int>;

const ll MOD = 1000000007;
const ll MAX = 100000000;

template<typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}

ll ifloor(ll a, ll b){
    if(b < 0) a *= -1, b *= -1;
    if(a < 0) return (a - b + 1) / b;
    else return a / b;
}

ll iceil(ll a, ll b){
    if(b < 0) a *= -1, b *= -1;
    if(a > 0) return (a + b - 1) / b;
    else return a / b;
}

int n, x;
string s;

struct F{
    ll sum = 0;
    vector<vector<ll>> pre, suf, cnt;
    ll sz = 0;
    ll two = 1;
    F(): pre(n, vector<ll>(n)), suf(n, vector<ll>(n)), cnt(n, vector<ll>(n)) {}
    F(char c): pre(n, vector<ll>(n)), suf(n, vector<ll>(n)), cnt(n, vector<ll>(n)), sz(1), two(2) {
        for(int i = 0; i < n; i++){
            if(s[i] != c) continue;
            cnt[i][i]++;
            pre[i][i]++;
            suf[i][i]++;
            if(n == 1) sum++;
        }
    }
};

F operator+(F& a, F& b){
    F c;
    c.two = a.two * b.two % MOD;
    c.sum = a.sum * b.two % MOD + b.sum * a.two % MOD;
    c.sz = a.sz + b.sz;
    c.sz %= MOD;

    for(int k = 0; k < n - 1; k++){
        c.sum += a.pre[0][k] * b.suf[k + 1][n - 1] % MOD;
    }
    c.sum %= MOD;
    
    for(int k = 0; k < n; k++){
        for(int i = 0; i <= k; i++){
            for(int j = k + 1; j < n; j++){
                c.pre[i][j] += a.pre[i][k] * b.cnt[k + 1][j] % MOD;
                c.suf[i][j] += a.cnt[i][k] * b.suf[k + 1][j] % MOD;
                c.cnt[i][j] += a.cnt[i][k] * b.cnt[k + 1][j] % MOD;
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            c.pre[i][j] += a.pre[i][j] + b.pre[i][j] * a.two % MOD;
            c.suf[i][j] += a.suf[i][j] * b.two % MOD + b.suf[i][j];
            c.cnt[i][j] += a.cnt[i][j] + b.cnt[i][j];
            c.pre[i][j] %= MOD;
            c.suf[i][j] %= MOD;
            c.cnt[i][j] %= MOD;
        }
    }

    return c;
}

int main(){
    StarBurstStream

    cin >> n >> x;
    cin >> s;


    vector<F> f(max(1, x) + 1);
    f[0] = F('0');
    f[1] = F('1');
    for(int i = 2; i <= x; i++){
        f[i] = f[i - 1] + f[i - 2];
        /*cerr << "test " << i << " " << f[i].sum << " " << f[i].sz << "\n";
        cerr << "pre\n";
        for(int j = 0; j < n; j++) printv(f[i].pre[j], cerr);
        cerr << "suf\n";
        for(int j = 0; j < n; j++) printv(f[i].suf[j], cerr);
        cerr << "cnt\n";
        for(int j = 0; j < n; j++) printv(f[i].cnt[j], cerr);*/
    }

    cout << f[x].sum << "\n";

    return 0;
}