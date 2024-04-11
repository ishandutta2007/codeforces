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

    vector<string> a(n + 2);
    a[0] = a[n + 1] = string(m + 2, '.');
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        a[i] = '.' + a[i] + '.';
    }

    vector<vector<bool>> vst(n + 2, vector<bool>(m + 2));
    vector<vector<bool>> vst2(n + 2, vector<bool>(m + 2));
    vector<pii> dir = {mp(0, 1), mp(1, 0), mp(0, -1), mp(-1, 0)};

    ll ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(vst[i][j]) continue;

            queue<pair<pii, int>> q2;
            queue<pii> q;
            q.push(mp(i, j));
            vst[i][j] = true;
            while(!q.empty()){
                int x = q.front().F, y = q.front().S;
                q.pop();
                bool b = false;
                for(pii d : dir){
                    int nx = x + d.F, ny = y + d.S;
                    if(a[nx][ny] != a[x][y]){
                        b = true;
                        continue;
                    }
                    if(vst[nx][ny]) continue;
                    q.push(mp(nx, ny));
                    vst[nx][ny] = true;
                }
                if(b){
                    q2.push(mp(mp(x, y), 1));
                    vst2[x][y] = true;
                }
            }
            while(!q2.empty()){
                int x = q2.front().F.F, y = q2.front().F.S, dis = q2.front().S;
                q2.pop();
                ans += dis;
                for(pii d : dir){
                    int nx = x + d.F, ny = y + d.S;
                    if(a[nx][ny] != a[x][y] || vst2[nx][ny]) continue;
                    q2.push(mp(mp(nx, ny), dis + 1));
                    vst2[nx][ny] = true;
                }
            }
        }
    }
    cout << ans << "\n";

    return 0;
}