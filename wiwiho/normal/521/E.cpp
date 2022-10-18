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

int n;
vector<vector<int>> g;
vector<int> in, low;
vector<vector<pii>> bcc;
stack<pii> st;
vector<vector<int>> tg;
vector<int> vst;
int ts = 0;

void init(){
    g.resize(n + 1);
    in.resize(n + 1, -1);
    low.resize(n + 1);
    tg.resize(n + 1);
    vst.resize(n + 1);
}

void tarjan(int now, int p){
    //cerr << "tarjan " << now << " " << p << "\n";
    in[now] = low[now] = ts++;
    if(now != p) st.push(mp(p, now));
    for(int i : g[now]){
        if(i == p) continue;
        if(in[i] != -1){
            low[now] = min(low[now], in[i]);
            if(in[i] < in[now]) st.push(mp(i, now));
            continue;
        }
        tarjan(i, now);
        low[now] = min(low[now], low[i]);
        if(low[i] < in[now]) continue;
        bcc.eb();
        //cerr << "cut " << now << "\n";
        while(true){
            pii tmp = st.top();
            st.pop();
            bcc.back().eb(tmp);
            if(tmp == mp(now, i)) break;
        }
    }
}

void solve(vector<pii>& e){
    if(e.size() <= 1) return;
    for(pii i : e){
        tg[i.F].clear();
        tg[i.S].clear();
        vst[i.F] = vst[i.S] = 0;
    }
    for(pii i : e){
        int u = i.F, v = i.S;
        tg[u].eb(v);
        tg[v].eb(u);
    }

    int rt = e[0].F;

    deque<int> path;
    int now = rt;
    while(true){
        vst[now] = 1;
        int p = path.empty() ? now : path.back();
        path.eb(now);
        //cerr << "path1 dfs " << now << " " << p << "\n";
        for(int i : tg[now]){
            if(i == p) continue;
            if(!vst[i]){
                now = i;
                break;
            }
            while(path.front() != i) path.pof;
            goto out;
        }
    }
    out:;

    for(int i : path) vst[i] = 2;

    /*cerr << "solve ";
    printv(e, cerr);
    printv(path, cerr);*/

    int sp = -1, s1 = -1, s2 = -1;
    for(int j = 0; j < path.size(); j++){
        int i = path[j];
        if(tg[i].size() >= 3){
            sp = i;
            s1 = path[j - 1 < 0 ? (int)path.size() - 1 : j - 1];
            s2 = path[j + 1 >= path.size() ? 0 : j + 1];
            break;
        }
    }
    if(sp == -1) return;
    
    int ep = -1;
    for(int i : tg[sp]){
        if(vst[i] != 2){
            rt = i;
            break;
        }
        if(i != s1 && i != s2){
            ep = i;
            break;
        }
    }

    deque<int> path2;

    function<void(int, int)> dfs;
    dfs = [&](int now, int p){
        vst[now] = 3;
        path2.eb(now);
        for(int i : tg[now]){
            if(i == p) continue;
            if(vst[i] == 3) continue;
            if(vst[i] == 2){
                if(i != sp){
                    ep = i;
                    return;
                }
                continue;
            }
            dfs(i, now);
            if(ep != -1) return;
        }
        path2.pob;
    };

    if(ep == -1) dfs(rt, sp);
    //printv(path2, cerr);
    //cerr << sp << " " << ep << "\n";

    vector<vector<int>> a(3);
    while(path.front() != sp){
        path.eb(path.front());
        path.pof;
    }
    //printv(path, cerr);

    for(int i : path){
        a[0].eb(i);
        if(i == ep) break;
    }

    a[1].eb(sp);
    while(path.back() != ep){
        a[1].eb(path.back());
        path.pob;
    }
    a[1].eb(ep);

    a[2].eb(sp);
    for(int i : path2) a[2].eb(i);
    a[2].eb(ep);

    cout << "YES\n";
    for(int i = 0; i < 3; i++){
        cout << a[i].size() << " ";
        printv(a[i], cout);
    }
    exit(0);

}

int main(){
    StarBurstStream

    int m;
    cin >> n >> m;

    init();
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u].eb(v);
        g[v].eb(u);
    }

    for(int i = 1; i <= n; i++){
        if(in[i] != -1) continue;
        tarjan(i, i);
    }
    /*printv(low, cerr);
    printv(in, cerr);*/

    for(auto& i : bcc) solve(i);
    cout << "NO\n";

    return 0;
}