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

set<pll> s;

void rm(ll l, ll r){
    set<pll>::iterator it;
    while(it = s.lower_bound(mp(l, -1)), it != s.end()){
        pll now = *it;
        swap(now.F, now.S);
        if(now.F > r) break;
        s.erase(it);
        if(now.F < l && now.S > r){
            s.insert(mp(l - 1, now.F));
            s.insert(mp(now.S, r + 1));
        }
        else if(now.F < l){
            s.insert(mp(l - 1, now.F));
        }
        else if(now.S > r){
            s.insert(mp(now.S, r + 1));
        }
    }
}

void add(ll l, ll r){
    rm(l, r);
    s.insert(mp(r, l));
}

void inv(ll l, ll r){
    set<pll>::iterator it;
    vector<pll> t;
    while(it = s.lower_bound(mp(l, -1)), it != s.end()){
        pll now = *it;
        swap(now.F, now.S);
        if(now.F > r) break;
        s.erase(it);
        if(now.F < l && now.S > r){
            t.eb(mp(l, r));
            s.insert(mp(l - 1, now.F));
            s.insert(mp(now.S, r + 1));
        }
        else if(now.F < l){
            t.eb(mp(l, now.S));
            s.insert(mp(l - 1, now.F));
        }
        else if(now.S > r){
            t.eb(mp(now.F, r));
            s.insert(mp(now.S, r + 1));
        }
        else t.eb(now);
    }

    ll lst = l;
    for(pll i : t){
        if(lst < i.F) s.insert(mp(i.F - 1, lst));
        lst = i.S + 1;
    }
    if(lst <= r) s.insert(mp(r, lst));
}

ll query(){
    if(s.empty()) return 1;
    if(s.begin()->S != 1) return 1;
    set<pll>::iterator it;
    while(it = s.begin(), next(it) != s.end() && next(it)->S == it->F + 1){
        pll now = *it;
        now.F = next(it)->F;
        s.erase(next(it));
        s.erase(s.begin());
        s.insert(now);
    }
    return s.begin()->F + 1;
}

int main(){
    StarBurstStream

    int n;
    cin >> n;
    while(n--){

        ll t, l, r;
        cin >> t >> l >> r;

        if(t == 1) add(l, r);
        else if(t == 2) rm(l, r);
        else if(t == 3) inv(l, r);

        cout << query() << "\n";

    }

    return 0;
}