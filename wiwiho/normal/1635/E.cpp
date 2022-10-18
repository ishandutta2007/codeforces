#include <bits/stdc++.h>
#include <bits/extc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define eb emplace_back
#define ef emplace_front
#define pob pop_back()
#define pof pop_front()
#define mp make_pair
#define F first
#define S second
#define uni(a) a.resize(unique(iter(a)) - a.begin())
#define printv(a, b) { \
    for(auto pv : a) b << pv << " "; \
    b << "\n"; \
}

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<ld, ld>;

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
    else return a/ b;
}

int n, m;
vector<vector<pii>> g;
vector<vector<int>> tg;
vector<int> ori;

void dfs(int now, int o){
    ori[now] = o;
    //cerr << now << " " << o << "\n";
    for(pii i : g[now]){
        if(i.S == 1){
            if(o == 0) tg[now].eb(i.F);
            else tg[i.F].eb(now);
        }
        else{
            if(o == 0) tg[i.F].eb(now);
            else tg[now].eb(i.F);
        }
        if(ori[i.F] != -1){
            if(ori[i.F] == o){
                //cerr << "OAO " << i.F << "\n";
                cout << "NO\n";
                exit(0);
            }
            continue;
        }
        dfs(i.F, !o);
    }
}

int main(){
    StarBurstStream;

    cin >> n >> m;
    g.resize(n + 1);
    tg.resize(n + 1);
    ori.resize(n + 1, -1);

    for(int i = 0; i < m; i++){
        int t, u, v;
        cin >> t >> u >> v;
        g[u].eb(mp(v, t));
        g[v].eb(mp(u, t));
    }

    for(int i = 1; i <= n; i++){
        if(ori[i] == -1) dfs(i, 0);
    }
    //cerr << "ok\n";

    vector<int> ans;
    queue<int> q;
    vector<int> deg(n + 1);

    for(int i = 1; i <= n; i++){
        for(int j : tg[i]) deg[j]++;
    }
    for(int i = 1; i <= n; i++){
        if(deg[i] == 0) q.push(i);
    }

    while(!q.empty()){
        int now = q.front();
        q.pop();
        ans.eb(now);
        for(int i : tg[now]){
            deg[i]--;
            if(deg[i] == 0) q.push(i);
        }
    }

    if(ans.size() != n){
        cout << "NO\n";
        return 0;
    }

    vector<int> pos(n + 1);
    for(int i = 0; i < n; i++) pos[ans[i]] = i;

    cout << "YES\n";
    for(int i = 1; i <= n; i++){
        if(ori[i] == 0) cout << 'L';
        else cout << 'R';
        cout << " " << pos[i] << "\n";
    }

    return 0;
}