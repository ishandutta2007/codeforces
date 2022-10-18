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
#define F first
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
const ll MAX = 2147483647;

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

void solve(){

    int n;
    cin >> n;

    vector<string> s(2);
    cin >> s[0] >> s[1];
    vector<vector<int>> g(2, vector<int>(n));
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < n; j++){
            if(s[i][j] == '*') g[i][j] = 1;
        }
    }


    vector<vector<ll>> dpl(n, vector<ll>(4, MAX));
    vector<vector<ll>> dpr(n, vector<ll>(4, MAX));
    
    dpl[0][g[0][0] * 2 + g[1][0]] = 0;
    dpr[n - 1][g[0][n - 1] * 2 + g[1][n - 1]] = 0;

    for(int i = 0; i < n; i++){
        if(i != 0){
            int u = g[0][i], d = g[1][i];
            for(int f = 0; f < 4; f++){
                int fu = f / 2, fd = f % 2;
                int tu = u || fu, td = d || fd;
                int to = tu * 2 + td;
                dpl[i][to] = min(dpl[i][to], dpl[i - 1][f] + fu + fd);
            }
        }
        dpl[i][0b01] = min({dpl[i][0b01], dpl[i][0b10] + 1, dpl[i][0b11] + 1});
        dpl[i][0b10] = min({dpl[i][0b10], dpl[i][0b01] + 1, dpl[i][0b11] + 1});
    }

    for(int i = n - 1; i >= 0; i--){
        if(i != n - 1){
            int u = g[0][i], d = g[1][i];
            for(int f = 0; f < 4; f++){
                int fu = f / 2, fd = f % 2;
                int tu = u || fu, td = d || fd;
                int to = tu * 2 + td;
                dpr[i][to] = min(dpr[i][to], dpr[i + 1][f] + fu + fd);
            }
        }
        dpr[i][0b01] = min({dpr[i][0b01], dpr[i][0b10] + 1, dpr[i][0b11] + 1});
        dpr[i][0b10] = min({dpr[i][0b10], dpr[i][0b01] + 1, dpr[i][0b11] + 1});
    }

    ll ans = MAX;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 4; j++){
            ll tans = dpl[i][j] + dpr[i][j] + (j == 3);
            ans = min(ans, tans);
        }
    }

    cout << ans << "\n";
}

int main(){
    StarBurstStream

    int T;
    cin >> T;
    while(T--) solve();

    return 0;
}