//#define NDEBUG

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
#define pob pop_back()
#define pof pop_front()
#define mp(a, b) make_pair(a, b)
#define F first
#define S second
#define mt make_tuple
#define gt(t, i) get<i>(t)
#define iceil(a, b) (((a) + (b) - 1) / (b))
#define tomax(a, b) ((a) = max((a), (b)))
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}

//#define TEST

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

vector<vector<ll>> operator*(vector<vector<ll>>& a, vector<vector<ll>>& b){
    vector<vector<ll>> c(a.size(), vector<ll>(b[0].size()));
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < b[0].size(); j++){
            for(int k = 0; k < b.size(); k++){
                c[i][j] += a[i][k] * b[k][j] % MOD;
                c[i][j] %= MOD;
            }
        }
    }
    return c;
}

int main(){
    StarBurstStream

    ll n, m;
    cin >> n >> m;

    ll tmp = n - m + 1;
    vector<vector<ll>> ans(m, vector<ll>(m));
    for(int i = 0; i < m; i++) ans[i][i] = 1;
    vector<vector<ll>> base(m, vector<ll>(m));
    base[0][0] = 1; base[0][m - 1] = 1;
    for(int i = 1; i < m; i++) base[i][i - 1] = 1;

    while(tmp > 0){
        if(tmp & 1) ans = ans * base;
        base = base * base;
        tmp >>= 1;
    }

    vector<vector<ll>> b(m, vector<ll>(1, 1));
    ans = ans * b;
    cout << ans[0][0] << "\n";

    return 0;
}