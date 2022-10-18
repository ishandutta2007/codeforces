//#define NDEBUG

#include <bits/stdc++.h>

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
#define B back()
#define FR front()
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}
#define pii pair<int, int>
#define pll pair<ll, ll>
#define modadd(a, b) (((a % MOD) + (b % MOD)) % MOD)
#define modtimes(a, b) (((a % MOD) * (b % MOD)) % MOD)
#define iceil(a) ((int)ceil((int)a))
#define ifloor(a) ((int)floor((int)a))

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

int main(){
    StarBurstStream

    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    map<vector<int>, vector<int>> t;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].eb(v);
        g[v].eb(u);
    }
    for(int i = 0; i < n; i++){
        lsort(g[i]);
        //cerr << i << "\n";
        //printv(g[i], cerr);
        t[g[i]].eb(i);
        if(t.size() > 3){
            cout << "-1\n";
            return 0;
        }
    }

    if(t.size() != 3){
        cout << "-1\n";
        return 0;
    }

    vector<int> ans(n);
    int now = 1;
    for(auto& p : t){
        if(p.F.size() + p.S.size() != n){
            cout << "-1\n";
            return 0;
        }
        for(int i : p.S) ans[i] = now;
        now++;
    }

    printv(ans, cout);

    return 0;
}