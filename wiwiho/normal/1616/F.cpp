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

const ll MOD = 3;
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

int mod3(int& v){
    while(v < 0) v += 3;
    while(v >= 3) v -= 3;
    return v;
}

void solve(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> tri;
    vector<vector<int>> g(n + 1, vector<int>(n + 1, -1));
    vector<int> clr(m, -1);

    for(int i = 0; i < m; i++){
        int u, v, c;
        cin >> u >> v >> c;
        g[u][v] = g[v][u] = i;
        if(c > 0) c--;
        clr[i] = c;
    }

    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            if(g[i][j] == -1) continue;
            for(int k = j + 1; k <= n; k++){
                if(g[i][k] == -1 || g[j][k] == -1) continue;
                //cerr << "triangle " << i << " " << j << " " << k << "\n";

                int tmp = 0, cnt = 0;
                tri.eb(vector<int>(m + 1));
                if(clr[g[i][j]] == -1) tri.back()[g[i][j]] = 1, cnt++;
                else tmp += clr[g[i][j]];
                if(clr[g[i][k]] == -1) tri.back()[g[i][k]] = 1, cnt++;
                else tmp += clr[g[i][k]];
                if(clr[g[j][k]] == -1) tri.back()[g[k][j]] = 1, cnt++;
                else tmp += clr[g[j][k]];
                
                tmp = 3 - tmp % 3;
                mod3(tmp);
                if(tmp != 0 && cnt == 0){
                    cout << "-1\n";
                    return;
                }

                tri.back()[m] = tmp;
            }
        }
    }

    int sz = tri.size();

    //cerr << "tri\n";
    //for(int i = 0; i < sz; i++) printv(tri[i], cerr);

    int r = 0;
    for(int i = 0; i < m && r < sz; i++){
        
        for(int j = r; j < sz; j++){
            if(tri[j][i] != 0){
                tri[r].swap(tri[j]);
                break;
            }
        }
        if(tri[r][i] == 0) continue;

        int tmp = tri[r][i];
        for(int j = i; j <= m; j++){
            tri[r][j] *= tmp;
            mod3(tri[r][j]);
        }

        for(int j = 0; j < sz; j++){
            if(j == r) continue;
            int tmp = tri[j][i];
            for(int k = i; k <= m; k++){
                tri[j][k] -= tri[r][k] * tmp;
                mod3(tri[j][k]);
            }
        }

        r++;
    }

    vector<int> ans = clr;
    for(int i = sz - 1; i >= 0; i--){
        int pos = -1;
        for(int j = 0; j < m; j++){
            if(tri[i][j] == 0) continue;
            pos = j;
            break;
        }
        if(pos == -1){
            if(tri[i][m] != 0){
                cout << "-1\n";
                return;
            }
            continue;
        }
        for(int j = m - 1; j > pos; j--){
            if(ans[j] == -1) ans[j] = 0;
            tri[i][m] -= tri[i][j] * ans[j];
            mod3(tri[i][m]);
        }
        ans[pos] = tri[i][m];
    }
    for(int i = 0; i < m; i++){
        if(ans[i] == -1) ans[i] = 0;
        ans[i]++;
    }

    printv(ans, cout);
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