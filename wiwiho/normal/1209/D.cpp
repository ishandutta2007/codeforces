//#define NDEBUG

#include <bits/stdc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); cerr.tie(0);
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
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define modadd(a, b) (((a % MOD) + (b % MOD)) % MOD)
#define modtimes(a, b) (((a % MOD) * (b % MOD)) % MOD)

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 10007;
const ll MAX = 1LL << 60;

vector<vector<int>> g;
vector<bool> visit;

int dfs(int n){
    visit[n] = true;
    int cnt = 1;
    for(int i : g[n]){
        if(visit[i]) continue;
        cnt += dfs(i);
    }
    return cnt;
}

int main(){
    StarBurstStream

    int n, k;
    cin >> n >> k;
    g.resize(n + 1);
    visit.resize(n + 1);

    for(int i = 0; i < k; i++){
        int x, y;
        cin >> x >> y;
        g[x].pb(y); g[y].pb(x);
    }

    int happy = 0;
    for(int i = 1; i <= n; i++){
        if(!visit[i]){
            happy += dfs(i) - 1;
        }
    }

    cout << k - happy << "\n";

    return 0;
}