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

vector<vector<int>> g1, g2;

vector<pii> tmp;
vector<vector<int>> o;
void dfs1(int now, int id, int cnt){
    tmp[now] = mp(id, cnt);
    o[id].eb(now);
    for(int i : g1[now]){
        if(tmp[i] != mp(-1, -1)){
//            cerr << "QQ " << now << " " << i << "\n";
            cout << "0\n";
            exit(0);
        }
        dfs1(i, id, cnt + 1);
    }
}

vector<int> vst;
vector<int> ans;

void dfs2(int now){
    vst[now] = 1;
    for(int i : g2[now]){
        if(vst[i] == 1){
            cout << "0\n";
            exit(0);
        }
        if(vst[i]) continue;
        dfs2(i);
    }
    vst[now] = 2;
    ans.eb(now);
}

int main(){
    StarBurstStream

    int n, k;
    cin >> n >> k;

    g1.resize(n + 1);
    tmp.resize(n + 1, mp(-1, -1));

    vector<int> p(n + 1);
    for(int i = 1; i <= n; i++) cin >> p[i];

    vector<int> in(n + 1), out(n + 1);
    for(int i = 0; i < k; i++){
        int u, v;
        cin >> u >> v;
        g1[u].eb(v);
        out[u]++; in[v]++;
    }
//    printv(in, cerr);
//    printv(out, cerr);
    for(int i = 1; i <= n; i++){
        if(in[i] > 1 || out[i] > 1){
            cout << "0\n";
            return 0;
        }
    }

    int id = 0;
    for(int i = 1; i <= n; i++){
        if(tmp[i] != mp(-1, -1) || in[i]) continue;
        o.eb();
        dfs1(i, id++, 0);
    }
    for(int i = 1; i <= n; i++){
        if(tmp[i] == mp(-1, -1)){
            cout << "0\n";
            return 0;
        }
    }
//    printv(tmp, cerr);

    g2.resize(id);
    vst.resize(id);
    for(int i = 1; i <= n; i++){
        int u = p[i];
        if(u == 0) continue;
        if(tmp[u].F == tmp[i].F){
            if(tmp[u].S > tmp[i].S){
//                cerr << u << " " << i << "\n";
                cout << "0\n";
                exit(0);
            }
            continue;
        }
        g2[tmp[u].F].eb(tmp[i].F);
    }
//    cerr << "test\n";
//    for(int i = 0; i < id; i++){
//        cerr << i << "  ";
//        printv(g2[i], cerr);
//    }

    for(int i = 0; i < id; i++){
        if(!vst[i]) dfs2(i);
    }
    reverse(iter(ans));

    for(int i : ans){
        for(int j : o[i]) cout << j << " ";
    }
    cout << "\n";

    return 0;
}