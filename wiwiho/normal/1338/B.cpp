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
ostream &operator<<(ostream &o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}

vector<vector<int>> g;
vector<int> d;

int mx;

void dfs(int now, int p){

    d[now] = d[p] + 1;
    int cnt = 0;
    for(int i : g[now]){
        if(i == p) continue;
        dfs(i, now);
        if(g[i].size() == 1) cnt++;
    }

    if(cnt > 0) mx -= cnt - 1;
}

int main(){
    StarBurstStream

    int n;
    cin >> n;

    g.resize(n + 1);
    d.resize(n + 1);
    mx = n - 1;

    int mn = 1;
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        g[u].eb(v);
        g[v].eb(u);
    }

    for(int i = 1; i <= n; i++){
        if(g[i].size() > 1){
            dfs(i, i);
            break;
        }
    }

    int tmp = -1;
    for(int i = 1; i <= n; i++){
        if(g[i].size() == 1){
            if(tmp == -1) tmp = d[i];
            else if(tmp % 2 != d[i] % 2) mn = 3;
        }
    }

    cout << mn << " " << mx << "\n";

    return 0;
}