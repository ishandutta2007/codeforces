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
ostream& operator<<(ostream& o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}

vector<vector<pii>> g;
vector<int> vst;
bool ans = true;

void dfs(int now, int c){
    vst[now] = 1;
    for(pii i : g[now]){
        if(i.S <= c || vst[i.F] == 2) continue;
        if(vst[i.F] == 1){
            ans = false;
            return;
        }
        dfs(i.F, c);
        if(!ans) return;
    }
    vst[now] = 2;
}

vector<int> in, tr, out;
int ts1 = 0, ts2 = 0;

void dfs2(int now, int c){
    in[now] = ts1++;
    tr[now] = ts2;
    for(pii i : g[now]){
        if(i.S <= c || tr[i.F] != 0) continue;
        dfs2(i.F, c);
    }
    out[now] = ts1++;
}

bool isAnc(int a, int b){
    return in[a] < in[b] && out[a] > out[b];
}

int main(){
    StarBurstStream

    int n, m;
    cin >> n >> m;

    g.resize(n + 1);
    vector<pair<int, pii>> e(m + 1);

    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v >> e[i].F;
        e[i].S = mp(u, v);
        g[u].eb(mp(v, e[i].F));
    }

    int l = 0, r = 1000000000;
    while(l < r){
        int mid = (l + r) / 2;
        vst.clear();
        vst.resize(n + 1);
        ans = true;
        for(int i = 1; i <= n && ans; i++){
            if(vst[i] == 0){
                dfs(i, mid);
            }
        }
        if(ans) r = mid;
        else l = mid + 1;
    }

    tr.resize(n + 1);
    in.resize(n + 1);
    out.resize(n + 1);
    for(int i = 1; i <= n; i++){
        if(tr[i] == 0){
            ts2++;
            dfs2(i, l);
        }
    }
//    printv(in, cerr);
//    printv(tr, cerr);
//    printv(out, cerr);

    vector<int> anse;
    for(int i = 1; i <= m; i++){
        if(e[i].F <= l){
            if(tr[e[i].S.F] < tr[e[i].S.S] || (tr[e[i].S.F] == tr[e[i].S.S] && (isAnc(e[i].S.S, e[i].S.F) || (!isAnc(e[i].S.F, e[i].S.S) && in[e[i].S.F] < in[e[i].S.S]))))
                anse.eb(i);
        }
    }

    cout << l << " " << anse.size() << "\n";
    printv(anse, cout);

    return 0;
}