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
#define iceil(a, b) (((a) + (b) - 1) / (b))
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

int n, k;
vector<int> t;
vector<vector<ll>> a;
vector<ll> sum;

void add(int id, vector<ll>& dp){
    for(int i = k; i >= t[id]; i--){
        dp[i] = max(dp[i], dp[i - t[id]] + sum[id]);
    }
}

ll ans = 0;
void dfs(int l, int r, vector<ll>& dp){
    if(l == r){
        for(int i = 0; i <= t[l] && k - i >= 0; i++){
            ans = max(ans, dp[k - i] + a[l][i]);
        }
        return;
    }

    int m = (l + r) / 2;
    vector<ll> tmp = dp;
    for(int i = m + 1; i <= r; i++) add(i, tmp);
    dfs(l, m, tmp);
    tmp = dp;
    for(int i = l; i <= m; i++) add(i, tmp);
    dfs(m + 1, r, tmp);
}

int main(){
    StarBurstStream

    cin >> n >> k;
    t.resize(n);
    a.resize(n);
    sum.resize(n);
    for(int i = 0; i < n; i++){
        cin >> t[i];
        a[i].resize(t[i] + 1);
        for(int j = 1; j <= t[i]; j++){
            cin >> a[i][j];
            sum[i] += a[i][j];
            a[i][j] += a[i][j - 1];
        }
    }

    vector<ll> dp(k + 1);
    dfs(0, n - 1, dp);
    cout << ans << "\n";

    return 0;
}