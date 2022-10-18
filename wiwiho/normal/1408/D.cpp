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

int main(){
    StarBurstStream

    int n, m;
    cin >> n >> m;

    vector<pii> r(n), s(m);
    for(int i = 0; i < n; i++) cin >> r[i].F >> r[i].S;
    for(int i = 0; i < m; i++) cin >> s[i].F >> s[i].S;
    lsort(s);

    vector<pii> ts;
    int mx = -1;
    for(int i = m - 1; i >= 0; i--){
        if(mx >= s[i].S) continue;
        mx = s[i].S;
        ts.eb(s[i]);
    }
    s = ts;
    m = s.size();
//    printv(s, cerr);

    vector<pair<int, pii>> t;
    for(int i = 0; i < n; i++){
        int lst = r[i].S;
        for(int j = 0; j < m; j++){
            if(r[i].F > s[j].F) break;
            if(r[i].S > s[j].S) continue;
            t.eb(mp(lst - r[i].S, mp(i, s[j].F - r[i].F + 1)));
            lst = s[j].S + 1;
        }
        t.eb(mp(lst - r[i].S, mp(i, 0)));
    }

    multiset<ll> now;
    for(int i = 0; i < n; i++) now.insert(MAX);
    vector<ll> lst(n, MAX);
    ll mn = MAX;
    lsort(t);
//    printv(t, cerr);
    for(auto i : t){
        ll y = i.F;
        int id = i.S.F;
        ll x = i.S.S;
//        cerr << y << " " << id << " " << x << "\n";
        now.erase(now.find(lst[id]));
        now.insert(x);
        lst[id] = x;
        mn = min(mn, *now.rbegin() + y);
    }

    cout << mn << "\n";

    return 0;
}