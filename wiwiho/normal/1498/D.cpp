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

int main(){
    StarBurstStream

    int n, m;
    cin >> n >> m;

    vector<bool> dp(m + 1);
    dp[0] = true;
    vector<int> ans(m + 1, -1);
    vector<vector<int>> anc(20, vector<int>(m + 2));
    for(int s = 1; s <= n; s++){
        int t;
        cin >> t;
        ll x, y;
        cin >> x >> y;

        for(int i = 0; i <= m + 1; i++){
            if(t == 2) anc[0][i] = min((ll)m + 1, iceil(i * x, 100000));
            else anc[0][i] = min((ll)m + 1, iceil(i * 100000LL + x, 100000));
        }
        for(int i = 1; i < 20; i++){
            for(int j = 0; j <= m + 1; j++){
                anc[i][j] = anc[i - 1][anc[i - 1][j]];
            }
        }

        vector<int> tmp;
//        cerr << y << "  ";
        for(int j = 0; (1 << j) <= y; j++){
            tmp.eb(1 << j);
            y -= 1 << j;
        }
        if(y) tmp.eb(y);
//        printv(anc[0], cerr);

        for(int i : tmp){
            for(int j = m; j >= 0; j--){
                if(!dp[j]) continue;
                int now = i;
                int v = j;
                while(now > 0){
                    v = anc[__lg(now)][v];
                    now -= 1 << __lg(now);
                }
//                cerr << s << " " << i << " " << v << "\n";
                if(v <= m) dp[v] = true;
            }
        }

        for(int i = 1; i <= m; i++){
            if(dp[i] && ans[i] == -1) ans[i] = s;
        }
//        printv(dp, cerr);

    }

    for(int i = 1; i <= m; i++) cout << ans[i] << " ";
    cout << "\n";


    return 0;
}