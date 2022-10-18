//#define NDEBUG

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

using namespace std;

ll pabs(pll a, pll b){
    return abs(a.F - b.F) + abs(a.S - b.S);
}

int main(){
    StarBurstStream

    int n;
    cin >> n;

    vector<pll> p(n);
    for(int i = 0; i < n; i++) cin >> p[i].F >> p[i].S;
    vector<ll> c(n), k(n);

    for(int i = 0; i < n; i++) cin >> c[i];
    for(int i = 0; i < n; i++) cin >> k[i];

    vector<ll> dis = c;
    vector<bool> visit(n);

    vector<int> from(n);
    for(int i = 0; i < n; i++) from[i] = i;

    ll ans = 0;

    for(int i = 0; i < n; i++){

        int now = -1;
        for(int j = 0; j < n; j++){
            if(visit[j]) continue;
            if(now == -1 || dis[j] < dis[now]) now = j;
        }
        visit[now] = true;
        ans += dis[now];

        for(int j = 0; j < n; j++){
            if(visit[j]) continue;
            if(pabs(p[now], p[j]) * (k[now] + k[j]) < dis[j]){
                from[j] = now;
                dis[j] = pabs(p[now], p[j]) * (k[now] + k[j]);
            }
        }

    }

    vector<pii> e;
    vector<int> v;
    for(int i = 0; i < n; i++){
        if(from[i] != i) e.eb(mp(i + 1, from[i] + 1));
        else v.eb(i + 1);
    }

    //printv(dis, cerr);

    cout << ans << "\n";

    cout << v.size() << "\n";
    printv(v, cout);

    cout << e.size() << "\n";
    for(pii p : e){
        cout << p.F << " " << p.S << "\n";
    }


    return 0;
}