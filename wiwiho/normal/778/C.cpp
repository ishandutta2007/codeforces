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

vector<vector<int>> g;
vector<int> cnt;
vector<vector<int>> dpt;

stack<pii> cnth;
stack<pii> gh;
int ts;

int newnode(){
    int id = ts++;
    fill(iter(g[id]), -1);
    return id;
}

void unionTree(int a, int b){
    for(int i = 0; i < 26; i++){
        if(g[b][i] == -1) continue;
        if(g[a][i] == -1){
            gh.push(mp(a, i));
            g[a][i] = newnode();
        }
        unionTree(g[a][i], g[b][i]);
    }
    cnth.push(mp(a, cnt[a]));
    cnt[a] = 1;
    for(int i = 0; i < 26; i++){
        if(g[a][i] != -1) cnt[a] += cnt[g[a][i]];
    }
}

void dfs(int now, int d){
    cnt[now] = 1;
    dpt[d].eb(now);
    for(int i = 0; i < 26; i++){
        if(g[now][i] == -1) continue;
        dfs(g[now][i], d + 1);
        cnt[now] += cnt[g[now][i]];
    }
}

int main(){
    StarBurstStream

    int n;
    cin >> n;

    g.resize(1e6, vector<int>(26, -1));
    for(int i = 0; i < n - 1; i++){
        int u, v;
        char c;
        cin >> u >> v >> c;
        g[u][c - 'a'] = v;
    }
    cnt.resize(1e6);
    dpt.resize(n + 1);

    dfs(1, 1);

    int ans = n, ansp = 1;
    for(int d = 1; d <= n; d++){
//        cerr << "test " << d << "\n";
        if(dpt[d].empty()) break;
        int qq = n;
        ts = n + 1;

        for(int i : dpt[d]){
            if(cnt[i] == 1) continue;
//            cerr << "qq " << i << "\n";
            int mx = -1;
            for(int j = 0; j < 26; j++){
                int now = g[i][j];
                if(now == -1) continue;
                if(mx == -1 || cnt[now] > cnt[mx]) mx = now;
            }
//            cerr << mx << " " << cnt[mx] << "\n";

            qq -= cnt[mx];
            for(int j = 0; j < 26; j++){
                int now = g[i][j];
                if(now == -1 || now == mx) continue;
                unionTree(mx, now);
                qq -= cnt[now];
//                cerr << now << " " << cnt[now] << "\n";
            }
            qq += cnt[mx];
//            cerr << "mx " << cnt[mx] << "\n";
            qq--;
        }

        if(qq < ans){
            ans = qq;
            ansp = d;
        }
//        cerr << d << " " << qq << "\n";

        while(!cnth.empty()){
            cnt[cnth.top().F] = cnth.top().S;
            cnth.pop();
        }
        while(!gh.empty()){
            g[gh.top().F][gh.top().S] = -1;
            gh.pop();
        }

    }

    cout << ans << "\n" << ansp << "\n";

    return 0;
}