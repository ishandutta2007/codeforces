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

ll calc(int n, ll k, ll d, vector<ll>& a){
    ll ans = 0;
    for(int i = 0; i < n; i++) ans += (d - a[i] % d) % d;
    return ans;
}

ll f(ll a, ll d){
    return (d - a % d) % d;
}

int main(){
    StarBurstStream

    int n;
    ll k;
    cin >> n >> k;

    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

//    for(int d = 1; d <= 100; d++) cerr << setw(5) << d << " ";
//    cerr << "\n";
//    for(int i = 0; i < n; i++){
////        cerr << i << " " << a[i] << "  ";
//        for(int d = 1; d <= 100; d++){
//            cerr << setw(5) << a[i] % d << " ";
//        }
//        cerr << "\n";
//        for(int d = 1; d <= 100; d++){
//            cerr << setw(5) << (d - a[i] % d) % d << " ";
//        }
//        cerr << "\n";
//    }
//    for(int d = 1; d <= 100; d++){
//        if(calc(n, k, d, a) >=0) cerr << setw(5) << calc(n, k, d, a) << " ";
//        else cerr << string(6, ' ');
//    }
//    cerr << "\n";

    vector<ll> p(1, 1);
    for(ll i : a){
        ll lst = MAX;
        for(ll j = 1; j * j <= i; j++){
            p.eb(iceil(i, j));
            lst = iceil(i, j);
//            cerr << lst << "\n";
        }
        for(ll j = 2; j < lst; j++){
            if(f(i, j) <= f(i, j - 1)) p.eb(j);
        }
    }
    p.eb(1e15);

    lsort(p);
    uni(p);
//    printv(p, cerr);

    ll ans = -1;
    for(int i = (int)p.size() - 2; i >= 0; i--){
        if(calc(n, k, p[i], a) > k) continue;
        ll l = p[i], r = p[i + 1] - 1;
//        cerr << l << " " << r << "\n";
        while(l < r){
            ll m = (l + r + 1) / 2;
            if(calc(n, k, m, a) <= k) l = m;
            else r = m - 1;
        }
        ans = l;
        break;
    }

    cout << ans << "\n";

    return 0;
}