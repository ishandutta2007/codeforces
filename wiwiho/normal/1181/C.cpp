//#define NDEBUG

#include <bits/stdc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define eb(a) emplace_back(a)
#define pf(a) push_front(a)
#define pob pop_back()
#define pof pop_front()
#define F first
#define S second
#define B back()
#define FR front()
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}
#define pii pair<int, int>
#define pll pair<ll, ll>
#define modadd(a, b) (((a % MOD) + (b % MOD)) % MOD)
#define modtimes(a, b) (((a % MOD) * (b % MOD)) % MOD)
#define iceil(a) ((int)ceil((int)a))
#define ifloor(a) ((int)floor((int)a))

//#define TEST

#define tiiii tuple<int, int, int, int>
#define tget(t, i) get<i>(t)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 998244353;
const ll MAX = 2147483647;

ostream& operator<<(ostream& o, tiiii t){
    return o << tget(t, 0) << "," << tget(t, 1) << "," << tget(t, 2) << "," << tget(t,3);
}

int main(){
    StarBurstStream

    int n, m;
    cin >> n >> m;

    vector<string> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<vector<int>> b(n, vector<int>(m, 1));
    for(int i = 1; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == a[i - 1][j]) b[i][j] = b[i - 1][j] + 1;
        }
    }

    vector<vector<tiiii>> f(n, vector<tiiii>(m + 1));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int color3 = a[i][j], cnt = b[i][j];
            if(i - cnt < 0 || b[i - cnt][j] != b[i][j]) continue;
            int color2 = a[i - cnt][j];
            if(i - cnt - cnt < 0 || b[i - cnt - cnt][j] < b[i][j]) continue;
            int color1 = a[i - cnt - cnt][j];
            f[i][j] = make_tuple(color1, color2, color3, cnt);
        }
    }

    //for(int i = 0; i < n; i++) printv(f[i], cerr);

    ll ans = 0;
    ll cnt;
    for(int i = 0; i < n; i++){
        cnt = tget(f[i][0], 3) != 0;
        for(int j = 1; j <= m; j++){

            if(tget(f[i][j], 3) == 0 || f[i][j] != f[i][j - 1]){
                ans += cnt * (cnt + 1) / 2;
                cnt = tget(f[i][j], 3) != 0;
                continue;
            }

            cnt++;

        }
    }

    cout << ans << "\n";

    return 0;
}