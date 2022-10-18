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

ll f(ll n, ll k){
    return (n / k) * (n / k) * (k - n % k) + iceil(n, k) * iceil(n, k) * (n % k);
}

int main(){
    StarBurstStream

    int n, k;
    cin >> n >> k;

    vector<ll> a(n);
    std::priority_queue<pair<ll, pii>> pq;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        pq.push(mp(a[i] * a[i] - f(a[i], 2), mp(i, 2)));
        ans += a[i] * a[i];
    }

    int cnt = n;
    while(cnt < k){
        cnt++;
        pair<ll, pii> t = pq.top();
//        cerr << t << "\n";
        pq.pop();
        ans -= t.F;
        pq.push(mp(f(a[t.S.F], t.S.S) - f(a[t.S.F], t.S.S + 1), mp(t.S.F, t.S.S + 1)));
    }

    cout << ans << "\n";

    return 0;
}