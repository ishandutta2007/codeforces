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
    if(pvaspace) b << " "; \
    pvaspace=true;\
    b << pva;\
}\
b << "\n";}
#define SZ(a) int(a.size())

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

int main(){
    StarBurstStream

    int R, C, n, K;
    cin >> R >> C >> n >> K;

    vector<pii> pt(n + 1);
    vector<vector<int>> col(C + 1);
    vector<vector<int>> row(R + 1);
    for(int i = 1; i <= n; i++){
        int x, y;
        cin >> x >> y;
        pt[i] = mp(x, y);
        col[y].eb(x);
        row[x].eb(y);
    }

    ll ans = 0;
    for(int x1 = 1; x1 <= R; x1++){
        vector<int> l(C + 2, -1), r(C + 2, -1), cnt(C + 2);
        vector<bool> ok(C + 2);
        ok[0] = ok[C + 1] = true;
        int lst = 0;
        for(int i = 1; i <= C; i++){
            for(int j : col[i]){
                if(j < x1) continue;
                cnt[i]++;
            }
            if(cnt[i] == 0) continue;
            if(lst != -1){
                l[i] = lst;
                r[lst] = i;
            }
            lst = i;
            ok[i] = true;
        }
        r[lst] = C + 1;
        l[C + 1] = lst;
        
        auto calc = [&](int y){
            int now = y;
            int c = cnt[y];
            while(now != C + 1 && c < K){
                now = r[now];
                c += cnt[now];
            }

            int pre = l[y];
            int len = y - pre - 1;
            ll tmp = (ll)(len + 1) * (now - y);
            tmp += (ll)len * (len + 1) / 2;
            //cerr << "calc " << y << " " << tmp << " " << len << " " << now << "\n";
            return tmp;
        };

        ll tmp = 0;
        for(int i = 1; i <= C + 1; i++){
            if(ok[i]) tmp += calc(i);
        }

        for(int x2 = R; x2 >= x1; x2--){
            //cerr << "owo " << x1 << " " << x2 << " " << tmp << "\n";
            ans += tmp;
            for(int y : row[x2]){
                int now = y;
                for(int i = 0; i <= K && now != 0; i++){
                    tmp -= calc(now);
                    now = l[now];
                }
                cnt[y]--;
                now = y;
                if(cnt[y] == 0){
                    tmp -= calc(r[y]);
                    r[l[y]] = r[y];
                    l[r[y]] = l[y];
                    ok[y] = false;
                    now = r[y];
                }
                for(int i = 0; i <= K && now != 0; i++){
                    tmp += calc(now);
                    now = l[now];
                }
            }
        }
    }

    ll total = (ll)R * (R + 1) / 2 * C * (C + 1) / 2;
    cout << total - ans << "\n";

    return 0;
}