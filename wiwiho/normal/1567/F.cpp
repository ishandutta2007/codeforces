
#include <bits/stdc++.h>
#include <bits/extc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0);
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

vector<int> dx = {0, 0, 1, -1};
vector<int> dy = {1, -1, 0, 0};

vector<vector<vector<pii>>> g;
vector<vector<int>> ans;

void dfs(int x, int y, int v){
    ans[x][y] = v;
    for(pii i : g[x][y]){
        if(ans[i.F][i.S] != -1) continue;
        dfs(i.F, i.S, v == 1 ? 4 : 1);
    }
}

int main(){
    StarBurstStream

    int n, m;
    cin >> n >> m;

    g.resize(n, vector<vector<pii>>(m));
    ans.resize(n, vector<int>(m, -1));

    vector<string> s(n);
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(s[i][j] == '.') continue;
            int cnt = 0;
            vector<pii> pos;
            for(int k = 0; k < 4; k++){
                if(s[i + dx[k]][j + dy[k]] == '.'){
                    cnt++;
                    pos.eb(mp(i + dx[k], j + dy[k]));
                }
            }
            if(cnt % 2){
                cout << "NO\n";
                return 0;
            }
            if(cnt == 0){
                ans[i][j] = 0;
            }
            else if(cnt == 2){
                ans[i][j] = 5;
                g[pos[0].F][pos[0].S].eb(pos[1]);
                g[pos[1].F][pos[1].S].eb(pos[0]);
            }
            else{
                ans[i][j] = 10;
                g[pos[0].F][pos[0].S].eb(pos[2]);
                g[pos[2].F][pos[2].S].eb(pos[0]);
                g[pos[1].F][pos[1].S].eb(pos[3]);
                g[pos[3].F][pos[3].S].eb(pos[1]);
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(ans[i][j] != -1) continue;
            dfs(i, j, 1);
        }
    }

    cout << "YES\n";
    for(int i = 0; i < n; i++) printv(ans[i], cout);

    return 0;
}