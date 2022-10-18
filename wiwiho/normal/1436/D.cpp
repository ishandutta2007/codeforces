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
#define topos(a) (((a) % MOD + MOD) % MOD)
#define uni(a) a.resize(unique(iter(a)) - a.begin())
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

vector<vector<int>> g;
vector<ll> mx, r, sz, a;

void dfs(int now, int p){
    bool leaf = true;
    for(int i : g[now]){
        if(i == p) continue;
        leaf = false;
        dfs(i, now);
        r[now] += r[i];
        if(mx[i] > mx[now]){
            r[now] += sz[now] * (mx[i] - mx[now]);
            mx[now] = mx[i];
        }
        else{
            r[now] += sz[i] * (mx[now] - mx[i]);
        }
        sz[now] += sz[i];
    }
    sz[now] += leaf;
    if(a[now] <= r[now]) r[now] -= a[now];
    else{
        a[now] -= r[now];
        mx[now] += iceil(a[now], sz[now]);
        r[now] = a[now] % sz[now] ? sz[now] - (a[now] % sz[now]) : 0;
    }
//    cerr << now << "  " << sz[now] << " " << r[now] << " " << mx[now] << "\n";
}


int main(){
    StarBurstStream

    int n;
    cin >> n;

    g.resize(n + 1);
    mx.resize(n + 1);
    r.resize(n + 1);
    sz.resize(n + 1);
    a.resize(n + 1);

    for(int i = 2; i <= n; i++){
        int p;
        cin >> p;
        g[p].eb(i);
    }
    for(int i = 1; i <= n; i++) cin >> a[i];
    dfs(1, 1);

    cout << mx[1] << "\n";

    return 0;
}