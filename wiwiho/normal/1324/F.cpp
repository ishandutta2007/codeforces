//#define NDEBUG

#include <bits/stdc++.h>
#include <bits/extc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define eb(a) emplace_back(a)
#define pf(a) push_front(a)
#define pob pop_back()
#define pof pop_front()
#define F first
#define S second
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}
#define pii pair<int, int>
#define pll pair<ll, ll>
#define tiii tuple<int, int, int>
#define mt make_tuple
#define gt(t, i) get<i>(t)
#define iceil(a, b) ((a) / (b) + !!((a) % (b)))

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;
using namespace __gnu_pbds;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

template<typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}

vector<int> mx, sub, mn, sum, pr, up;
vector<vector<int>> g;
vector<int> a;

void dfs(int now, int p){
    pr[now] = p;
    sum[now] = a[now];
    for(int i : g[now]){
        if(i == p) continue;
        dfs(i, now);
        sum[now] += sum[i];
    }
}

void dfs2(int now, int p){
    if(now == p) mx[now] = sum[now];
    else mx[now] = max(mx[p], sum[now]);
    for(int i : g[now]){
        if(i == p) continue;
        dfs2(i, now);
        sub[now] += mn[i];
    }
    mn[now] = min(sub[now], sum[now]);
}

void dfs3(int now, int p){
    if(now != p) up[now] = min({up[p], sub[p] - mn[now] + up[p], sum[0] - sum[now]});
    for(int i : g[now]){
        if(i == p) continue;
        dfs3(i, now);
    }
}

int main(){
    StarBurstStream

    int n;
    cin >> n;

    a.resize(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] == 0) a[i] = -1;
    }

    g.resize(n);
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v; u--; v--;
        g[u].eb(v);
        g[v].eb(u);
    }
    mx.resize(n);
    mn.resize(n);
    sum.resize(n);
    pr.resize(n);
    sub.resize(n);
    up.resize(n);

    dfs(0, 0);
    dfs2(0, 0);
    dfs3(0, 0);

//    printv(sum, cerr);
//    printv(mx, cerr);
//    printv(mn, cerr);

    for(int i = 0; i < n; i++){
        int ans = sum[0] - sub[i] - up[i];
        cout << ans << " ";
    }
    cout << "\n";

    return 0;
}