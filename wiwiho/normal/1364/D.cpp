//#define NDEBUG

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
#define pob pop_back()
#define pof pop_front()
#define mp(a, b) make_pair(a, b)
#define F first
#define S second
#define mt make_tuple
#define gt(t, i) get<i>(t)
#define iceil(a, b) (((a) + (b) - 1) / (b))
#define tomax(a, b) ((a) = max((a), (b)))
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}

//#define TEST

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
ostream &operator<<(ostream &o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}


vector<vector<int>> g;

vector<int> tmp;
vector<int> c;
vector<int> vst;

void dfs(int now, int p){
    if(!c.empty()) return;

    tmp.eb(now);
    vst[now] = tmp.size();

    int t = -1;
    for(int i : g[now]){
        if(vst[i] == 0 || vst[i] == -1 || i == p) continue;
        if(t == -1 || vst[t] < vst[i]) t = i;
    }
    if(t != -1){
        while(!tmp.empty()){
            c.eb(tmp.back());
            if(tmp.back() == t) break;
            tmp.pob;
        }
        return;
    }

    for(int i : g[now]){
        if(!vst[i]) dfs(i, now);
    }

    vst[now] = -1;
    tmp.pob;
}

vector<int> cr;
vector<int> c1, c2;

void dfs2(int now, int cc){
    cr[now] = cc;
    if(cc == 1) c1.eb(now);
    else c2.eb(now);
    for(int i : g[now]){
        if(!cr[i]) dfs2(i, cc == 1 ? 2 : 1);
    }
}

int main(){
    StarBurstStream

    int n, m, k;
    cin >> n >> m >> k;

    g.resize(n + 1);
    vst.resize(n + 1);
    cr.resize(n + 1);

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u].eb(v);
        g[v].eb(u);
    }

    for(int i = 1; i <= n; i++){
        if(!vst[i]) dfs(i, i);
    }

//    printv(c, cerr);

    if(c.empty()){
        dfs2(1, 1);
        if(c1.size() < c2.size()) c1.swap(c2);

        cout << "1\n";
        for(int i = 0; i < (k + 1) / 2; i++){
            cout << c1[i] << " ";
        }
        cout << "\n";
        return 0;
    }

    if(c.size() <= k){
        cout << "2\n" << c.size() << "\n";
        printv(c, cout);
        return 0;
    }

    cout << "1\n";
    for(int i = 0; i < (k + 1) / 2; i++){
        cout << c[i * 2] << " ";
    }
    cout << "\n";


    return 0;
}