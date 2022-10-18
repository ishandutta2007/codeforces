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

int n;
vector<vector<pair<int, pii>>> g;
vector<int> ep;
vector<vector<bool>> vst;
vector<vector<char>> ans;
int ts = 0;

void dfs(int now, pii e){
    if(e != mp(-1, -1)) vst[e.F][e.S] = true;
    while(ep[now] < g[now].size()){
        auto i = g[now][ep[now]];
        ep[now]++;
        if(vst[i.S.F][i.S.S]) continue;
        dfs(i.F, i.S);
    }
    if(e != mp(-1, -1)){
        ans[e.F][e.S] = ts % 2 ? 'R' : 'L';
        ts++;
    }
}

int main(){
    StarBurstStream;

    int m;
    cin >> m;
    //m = 1;
    
    vector<vector<int>> a(m + 1);
    ans.resize(m + 1);
    vector<int> discr;
    vst.resize(m + 1);
    for(int i = 1; i <= m; i++){
        int k;
        cin >> k;
        //k = 200000;
        a[i].resize(k + 1);
        vst[i].resize(k + 1);
        ans[i].resize(k + 1);
        for(int j = 1; j <= k; j++){
            cin >> a[i][j];
            //a[i][j] = 1;
            discr.eb(a[i][j]);
        }
    }

    lsort(discr);
    uni(discr);
    n = m + discr.size();
    g.resize(n + 1);
    ep.resize(n + 1);
    
    for(int i = 1; i <= m; i++){
        for(int j = 1; j < (int)a[i].size(); j++){
            int id = lower_bound(iter(discr), a[i][j]) - discr.begin();
            id += m + 1;
            g[i].eb(mp(id, mp(i, j)));
            g[id].eb(mp(i, mp(i, j)));
        }
    }

    for(int i = 1; i <= n; i++){
        if(g[i].size() % 2){
            cout << "NO\n";
            return 0;
        }
    }

    for(int i = 1; i <= n; i++){
        dfs(i, mp(-1, -1));
    }

    cout << "YES\n";
    for(int i = 1; i <= m; i++){
        for(int j = 1; j < (int)ans[i].size(); j++) cout << ans[i][j];
        cout << "\n";
    }


    return 0;
}