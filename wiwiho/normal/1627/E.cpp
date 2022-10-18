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
const ll MAX = 1LL << 60;

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

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> room(n + 1);
    vector<pair<pii, pii>> lad(k);
    vector<ll> h(k);
    vector<ll> x(n + 1);

    for(int i = 1; i <= n; i++) cin >> x[i];

    room[1].eb(1);
    room[n].eb(m);

    for(int i = 0; i < k; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d >> h[i];
        lad[i] = mp(mp(a, b), mp(c, d));
        room[a].eb(b);
        room[c].eb(d);
    }

    vector<vector<vector<pair<pii, ll>>>> go(n + 1);
    vector<vector<ll>> dp(n + 1);
    for(int i = 1; i <= n; i++){
        lsort(room[i]);
        uni(room[i]);
        go[i].resize(room[i].size());
        dp[i].resize(room[i].size(), MAX);
    }
    dp[1][0] = 0;

    for(int i = 0; i < k; i++){
        int a, b, c, d;
        pii r1, r2;
        tie(r1, r2) = lad[i];
        tie(a, b) = r1;
        tie(c, d) = r2;
        b = lower_bound(iter(room[a]), b) - room[a].begin();
        d = lower_bound(iter(room[c]), d) - room[c].begin();
        go[a][b].eb(mp(mp(c, d), h[i]));
    }

    for(int i = 1; i <= n; i++){
        
        for(int j = 1; j < room[i].size(); j++){
            dp[i][j] = min(dp[i][j], dp[i][j - 1] + x[i] * (room[i][j] - room[i][j - 1]));
        }
        for(int j = (int)room[i].size() - 2; j >= 0; j--){
            dp[i][j] = min(dp[i][j], dp[i][j + 1] + x[i] * (room[i][j + 1] - room[i][j]));
        }

        for(int j = 0; j < room[i].size(); j++){
            if(dp[i][j] == MAX) continue;
            for(auto t : go[i][j]){
                int f = t.F.F, c = t.F.S, hh = t.S;
                dp[f][c] = min(dp[f][c], dp[i][j] - hh);
            }
        }

    }

    if(dp[n].back() == MAX) cout << "NO ESCAPE\n";
    else cout << dp[n].back() << "\n";

}

int main(){
    StarBurstStream

    int T;
    cin >> T;
    while(T--){
        solve();
    }

    return 0;
}