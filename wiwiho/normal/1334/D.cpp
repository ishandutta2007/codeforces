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

ll findk(ll n, ll t){
    ll l = 0, r = n - 1;
    while(l < r){
        ll m = (l + r + 1) / 2;
        if((2 * n - 1 - m) * m / 2 < t) l = m;
        else r = m - 1;
    }
    return l + 1;
}

ll getnum(ll n, ll i){
    if(i == n * (n - 1) + 1) return 1;
    ll k = findk(n, (i + 1) / 2);
//    cerr << n << " " << i << " " << (i + 1) / 2 << " " << k << "\n";
    if(i % 2 == 1) return k;
    else return k + (i + 1) / 2 - ((n - 1 + n - (k - 1)) * (k - 1) / 2);
}

int main(){
    StarBurstStream
    cerr.tie(0);

    int T;
    cin >> T;

    while(T--){

        ll n, l, r;
        cin >> n >> l >> r;
//        cerr << l << " " << r << "\n";

        for(ll i = l; i <= r; i++) cout << getnum(n, i) << " ";
        cout << "\n";

    }

    return 0;
}