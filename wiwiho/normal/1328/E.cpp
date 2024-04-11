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

vector<vector<int>> g;

vector<int> in, out, d, pr;
int ts = 0;

void dfs(int now, int p){
    if(now != p) d[now] = d[p] + 1;
    in[now] = ts++;
    pr[now] = p;
    for(int i : g[now]){
        if(i == p) continue;
        dfs(i, now);
    }
    out[now] = ts++;
}

bool isAnc(int a, int b){
    return in[a] <= in[b] && out[a] >= out[b];
}

bool comp(int a, int b){
    return d[a] < d[b];
}

int main(){
    StarBurstStream

    int n, m;
    cin >> n >> m;

    g.resize(n + 1);
    in.resize(n + 1);
    out.resize(n + 1);
    d.resize(n + 1);
    pr.resize(n + 1);

    for(int i = 0 ; i <n - 1; i++){
        int u, v;
        cin >> u >> v;
        g[u].eb(v);
        g[v].eb(u);
    }

    dfs(1, 1);

    while(m--){
        int k;
        cin >> k;

        vector<int> t(k);
        for(int i = 0; i < k ;i++){
            cin >> t[i];
            t[i] = pr[t[i]];
        }

//        printv(t, cerr);

        sort(iter(t), comp);

        bool ans = true;
        for(int i = 1; i < k; i++){
            if(!isAnc(t[i - 1], t[i])) ans = false;
        }
        if(ans) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}