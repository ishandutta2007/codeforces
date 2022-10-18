//#define NDEBUG
 
#include <bits/stdc++.h>
 
#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
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
#define modadd(a, b) (((a % MOD) + (b % MOD)) % MOD)
#define modtimes(a, b) (((a % MOD) * (b % MOD)) % MOD)
 
//#define TEST
 
typedef long long ll;
typedef unsigned long long ull;
 
using namespace std;
 
const ll MOD = 1000000007;
const ll MAX = 2147483647;

vector<int> p;
vector<ll> dsus;
int n;

void initDSU(int n){
    for(int i = 0; i < n; i++){
        p[i] = i;
        dsus[i] = 1;
    }
}

int findDSU(int x){
    if(p[x] == x) return x;
    p[x] = findDSU(p[x]);
    return p[x];
}

void unionDSU(int a, int b){
    int pa = findDSU(a), pb = findDSU(b);
    if(pa == pb) return;
    dsus[pb] += dsus[pa];
    p[pa] = pb;
}

int main(){
    StarBurstStream

    int n, m;
    cin >> n >> m;

    p.resize(n + 1);
    dsus.resize(n + 1);
    initDSU(n + 1);

    map<int, vector<pii>> e;
    for(int i = 0; i < n - 1; i++){
        int u, v, w;
        cin >> u >> v >> w;
        e[w].pb(mp(u, v));
    }

    vector<ll> ans(200005);
    for(auto it = e.begin(); it != e.end(); it++){
        for(pii p : it->S){
            ans[it->F] += dsus[findDSU(p.F)] * dsus[findDSU(p.S)];
            unionDSU(p.F, p.S);
        }
    }
    for(int i = 1; i <= 200000; i++) ans[i] += ans[i - 1];
    
    for(int i = 0; i < m; i++){
        int q;
        cin >> q;
        cout << ans[q] << " ";
    }
    cout << "\n";

    return 0;
}