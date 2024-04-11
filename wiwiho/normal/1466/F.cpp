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

vector<int> dsu;

int findDSU(int a){
    if(dsu[a] != a) dsu[a] = findDSU(dsu[a]);
    return dsu[a];
}

void unionDSU(int a, int b){
    a = findDSU(a); b = findDSU(b);
    dsu[b] = a;
}

int main(){
    StarBurstStream

    int n, m;
    cin >> n >> m;

    vector<pii> v(n);
    dsu.resize(m + 1);
    vector<bool> r(n);
    for(int i = 1; i <= m; i++) dsu[i] = i;
    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        if(k == 1){
            cin >> v[i].S;
        }
        else{
            cin >> v[i].F >> v[i].S;
        }
    }

    for(int i = 0; i < n; i++){
        if(findDSU(v[i].F) == findDSU(v[i].S)) continue;
        unionDSU(v[i].F, v[i].S);
        r[i] = true;
    }

    int cnt = 0;
    vector<int> ans;
    for(int i = 0; i < n; i++){
        if(r[i]) cnt++, ans.eb(i + 1);
    }

    ll t = 1;
    for(int i = 0; i < cnt; i++){
        t *= 2;
        t %= MOD;
    }

    cout << t << " " << cnt << "\n";
    printv(ans, cout);

    return 0;
}