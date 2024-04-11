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
#define iceil(a) ((int)ceil(a))
#define ifloor(a) ((int)floor(a))

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

    vector<ll> now(n + 1);
    for(int i = 0; i < m; i++){
        int u, v;
        ll d;
        cin >> u >> v >> d;
        now[u] -= d;
        now[v] += d;
    }
    //printv(now, cerr);

    vector<int> pos, neg;
    for(int i = 1; i <= n; i++){
        if(now[i] > 0) pos.eb(i);
        else if(now[i] < 0) neg.eb(i);
    }
    //printv(pos, cerr);
    //printv(neg, cerr);

    vector<pair<pii, ll>> ans;
    int p = 0;
    for(int i : neg){
        while(now[i]){
            while(now[pos[p]] == 0) p++;
            ll t = min(-now[i], now[pos[p]]);
            ans.eb(mp(mp(i, pos[p]), t));
            now[i] += t;
            now[pos[p]] -= t;
        }
    }

    cout << ans.size() << "\n";
    for(auto i : ans) cout << i.F.F << " " << i.F.S << " " << i.S << "\n";

    return 0;
}