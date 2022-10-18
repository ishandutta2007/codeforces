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

    ll n, m;
    cin >> n >> m;

    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    set<ll> l, r;

    for(ll i = 0; i < (1LL << (n / 2)); i++){
        ll sum = 0;
        for(int j = 0; j < n / 2; j++){
            if(i & (1LL << j)) sum = (sum + a[j]) % m;
        }
        //if(sum >= m) cerr << sum << "\n";
        l.insert(sum);
    }

    for(ll i = 0; i < (1LL << ((n + 1) / 2)); i++){
        ll sum = 0;
        for(int j = 0; j < (n + 1) / 2; j++){
            if(i & (1LL << j)){
                //cerr << j + n/2 << " ";
                sum = (sum + a[j + n / 2]) % m;
            }
        }
        //cerr << "\n";
        r.insert(sum);
    }

    //cerr << *l.rbegin() << "\n";

    ll ans = 0;
    for(ll i : r) ans = max(ans, i);
    for(ll i : l) ans = max(ans, i);
    //cerr << l.size() << ' ' << r.size() << "\n";
    //printv(l, cerr);
    //printv(r, cerr);
    for(ll i : r){
        if(l.lower_bound(m - i) != l.begin()){
            ans = max(ans, *prev(l.lower_bound(m - i)) + i);
        }
        if(!l.empty()) ans = max(ans, (*l.rbegin() + i) % m);
    }
    cout << ans << "\n";

    return 0;
}