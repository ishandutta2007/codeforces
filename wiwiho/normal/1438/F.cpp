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

int lca;
pair<bool, bool> dfs(int now, int p, int a, int b){
    pair<bool, bool> bb = mp(false, false);
    if(now == a) bb.F = true;
    if(now == b) bb.S = true;
    for(int i : g[now]){
        if(i == p) continue;
        pair<bool, bool> tmp = dfs(i, now, a, b);
        bb.F |= tmp.F;
        bb.S |= tmp.S;
    }
    if(bb.F && bb.S && lca == -1) lca = now;
    return bb;
}

int tquery(int a, int b, int c){
    lca = -1;
    dfs(c, c, a, b);
    cout << "r " << lca << "\n" << flush;
    return lca;
}

//#define TEST

int query(int a, int b, int c){
    cout << "? " << a << " " << b << " " << c << "\n" << flush;
#ifdef TEST
    return tquery(a, b, c);
#endif
    int r;
    cin >> r;
    return r;
}

int main(){
    StarBurstStream

    int h;
    cin >> h;
    int n = (1 << h) - 1;
#ifdef TEST
    g.resize(n + 1);

    vector<int> t(n);
    for(int i = 0; i < n; i++) cin >> t[i];
    for(int i = 0; i < n; i++){
        if(i * 2 + 1 < n) g[t[i]].eb(t[i * 2 + 1]), g[t[i * 2 + 1]].eb(t[i]);
        if(i * 2 + 2 < n) g[t[i]].eb(t[i * 2 + 2]), g[t[i * 2 + 2]].eb(t[i]);
    }
#endif

    mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> dis0(1, n), dis1(1, n - 1), dis2(1, n - 2);

    vector<int> cnt(n + 1);
    for(int i = 0; i < 420; i++){
        int a = dis0(rnd);
        int b = dis1(rnd);
        if(b >= a) b++;
        int c = dis2(rnd);
        if(min(a, b) <= c) c++;
        if(max(a, b) <= c) c++;
        cnt[query(a, b, c)]++;
    }
//    printv(cnt, cerr);

    int f1 = -1, f2 = -1;
    for(int i = 1; i <= n; i++){
        if(f1 == -1 || cnt[i] > cnt[f1]){
            if(f1 != -1 && (f2 == -1 || cnt[f1] > cnt[f2])) f2 = f1;
            f1 = i;
        }
        else if(f2 == -1 || cnt[i] > cnt[f2]) f2 = i;
    }
//    cerr << f1 << " " << f2 << "\n";

    for(int i = 1; i <= n; i++){
        if(i == f1 || i == f2) continue;
        if(query(f1, f2, i) == i){
            cout << "! " << i << "\n" << flush;
            break;
        }
    }

    return 0;
}