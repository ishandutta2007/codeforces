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
#define topos(a) (((a) % MOD + MOD) % MOD)
#define uni(a) a.resize(unique(iter(a)) - a.begin())
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
ostream &operator<<(ostream &o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}

int n, m;
vector<vector<int>> g, g2;

bool check(int ans){
    vector<vector<bool>> dp0(1 << n, vector<bool>(n));
    vector<vector<bool>> dp1(1 << n, vector<bool>(n));
    dp0[1][0] = true;
    for(int i = 0; i < (1 << n); i++){
        for(int j = 0; j < n; j++){
            if(!(i & (1 << j))) continue;
            for(int k = 0; k < n; k++){
                if(!(i & (1 << k))) continue;
                if(g[k][j] >= ans && dp0[i xor (1 << j)][k]){
                    dp0[i][j] = true;
                }
                if(g[k][j] >= ans && dp1[i xor (1 << j)][k]){
                    dp1[i][j] = true;
                }
                if(g2[k][j] >= ans && dp0[i xor (1 << j)][k]){
                    dp1[i][j] = true;
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(g[i][0] >= ans && dp1[(1 << n) - 1][i]) return true;
        if(g2[i][0] >= ans && dp0[(1 << n) - 1][i]){
            return true;
        }
    }
    return false;
}

int main(){
    StarBurstStream

    cin >> n >> m;
    g.resize(n, vector<int>(n));
    g2.resize(n, vector<int>(n));

    vector<vector<int>> a(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int w = 1000000000;
            int w2 = 1000000000;
            for(int k = 0; k < m; k++){
                w = min(w, abs(a[i][k] - a[j][k]));
                w2 = min(w2, abs(a[i][k] - a[j][k + 1]));
            }
            g[i][j] = w;
            g2[i][j] = w2;
        }
    }

    int l = 0, r = 1000000000;
    while(l < r){
        int mid = (l + r + 1) / 2;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l << "\n";

    return 0;
}