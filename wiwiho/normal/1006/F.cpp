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

int main(){
    StarBurstStream

    int n, m;
    ll k;
    cin >> n >> m >> k;

    vector<map<ll, ll>> dp1(n), dp2(n);

    vector<vector<ll>> a(n, vector<ll>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cin >> a[i][j];
    }

    for(int i = 0; i < (1 << (n - 1)); i++){
        int x = 0, y = 0;
        ll now = a[0][0];
        for(int j = 0; j < n - 1; j++){
            if(1 << j & i) y++;
            else x++;
            if(y >= m) goto nxt1;
            now ^= a[x][y];
        }
//        cerr << "1 " << x << " " << now << "\n";
        dp1[x][now]++;
        nxt1:;
    }

    for(int i = 0; i < (1 << (m - 1)); i++){
        int x = n - 1, y = m - 1;
        ll now = a[x][y];
        for(int j = 0; j < m - 1; j++){
            if(1 << j & i) y--;
            else x--;
            if(x < 0) goto nxt2;
            now ^= a[x][y];
        }
        now ^= a[x][y];
//        cerr << "2 " << x << " " << now << "\n";
        dp2[x][now]++;
        nxt2:;
    }

    ll ans = 0;
    for(int i = 0; i < n; i++){
        for(auto j : dp1[i]){
            ans += j.S * dp2[i][k ^ j.F];
        }
    }

    cout << ans << "\n";

    return 0;
}