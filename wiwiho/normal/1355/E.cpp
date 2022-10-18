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

ll n, a, r, m;
vector<ll> h;

ll check(ll e){
    if(e < 0) return 1LL << 61;

    ll neg = 0, pos = 0;
    for(ll i : h){
        if(e - i < 0) neg += i - e;
        else pos += e - i;
    }

    ll ans = 0;
    ll t = min(neg, pos);
    neg -= t;
    pos -= t;
    ans += t * m;
    if(neg) ans += neg * r;
    if(pos) ans += pos * a;

    return ans;
}

int main(){
    StarBurstStream

    cin >> n >> a >> r >> m;
    m = min(m, a + r);
    h.resize(n);
    for(int i = 0; i < n; i++) cin >> h[i];

//    for(int i = 0; i <= 100; i++){
//        cerr << i << " " << check(i) << " " << check(i) - check(i - 1) << "\n";
//    }

    ll l = 0, r = (1LL << 30);
    while(l < r){
        ll m = (l + r + 1) / 2;
        if(check(m) < check(m - 1)) l = m;
        else r = m - 1;
    }
    cout << check(l) << "\n";

    return 0;
}