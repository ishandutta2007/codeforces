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


int main(){
    StarBurstStream

    int n;
    cin >> n;

    vector<ll> m(n);
    for(int i =0 ;i < n; i++) cin >> m[i];

    vector<ll> l(n);
    deque<pair<ll, pll>> dq;
    dq.eb(mp(-MAX, mp(0, -1)));
    ll now = 0;
    for(int i = 0; i < n; i++){
        while(dq.back().F > m[i]) now -= dq.back().S.F, dq.pob;
        dq.eb(mp(m[i], mp(m[i] * (i - dq.back().S.S), i)));
        now += dq.back().S.F;
        l[i] = now;
    }

    vector<ll> r(n);
    dq.clear();
    dq.eb(mp(-MAX, mp(0, n)));
    now = 0;
    for(int i = n - 1; i >= 0; i--){
        while(dq.back().F > m[i]) now -= dq.back().S.F, dq.pob;
        dq.eb(mp(m[i], mp(m[i] * (dq.back().S.S - i), i)));
        now += dq.back().S.F;
        r[i] = now;
    }

//    printv(l, cerr);
//    printv(r, cerr);

    ll ans = 0;
    for(int i = 1; i < n; i++){
        if(l[i] + r[i] - m[i] > l[ans] + r[ans] - m[ans]) ans = i;
    }

    vector<ll> v(n);
    ll lst = m[ans];
    v[ans] = lst;
    for(int i = ans - 1; i >= 0; i--){
        lst = min(m[i], lst);
        v[i] = lst;
    }
    lst = m[ans];
    for(int i = ans + 1; i < n; i++){
        lst = min(m[i], lst);
        v[i] = lst;
    }

    printv(v, cout);

    return 0;
}