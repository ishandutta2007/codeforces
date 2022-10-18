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

    int T;
    cin >> T;
    vector<pii> dir = {mp(0, 1), mp(1, 0), mp(0, -1), mp(-1, 0)};
    while(T--){
        int n, m;
        cin >> n >> m;

        vector<vector<bool>> vst(n + 2, vector<bool>(m + 2));
        vector<vector<int>> a(n + 2, vector<int>(m + 2, -10));
        vector<pair<int, pii>> tmp;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cin >> a[i][j];
                tmp.eb(mp(a[i][j], mp(i, j)));
            }
        }
        lsort(tmp);

        for(auto t : tmp){
            int tx = t.S.F, ty = t.S.S;
            if(vst[tx][ty]) continue;
            queue<pii> q;
            q.push(mp(tx, ty));
            vst[tx][ty] = true;

            while(!q.empty()){
                int x = q.front().F, y = q.front().S;
                q.pop();
                for(pii d : dir){
                    int nx = x + d.F, ny = y + d.S;
                    if(vst[nx][ny]) continue;
//                    cerr << x << " " << y << " " << nx << " " << ny << " " << a[x][y] << " " << a[nx][ny] << "\n";
                    if(a[nx][ny] == a[x][y]){
//                        cerr << "test1\n";
                        a[nx][ny]++;
                        vst[nx][ny] = true;
                        q.push(mp(nx, ny));
                    }
                    else if(a[nx][ny] == a[x][y] - 1){
//                        cerr << "test2\n";
                        vst[nx][ny] = true;
                        q.push(mp(nx, ny));
                    }
                }
            }
        }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++) cout << a[i][j] << " ";
            cout << "\n";
        }

    }

    return 0;
}