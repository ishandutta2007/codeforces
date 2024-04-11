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
#define pob pop_back()
#define pof pop_front()
#define mp(a, b) make_pair(a, b)
#define F first
#define S second
#define mt make_tuple
#define gt(t, i) get<i>(t)
#define iceil(a, b) ((a + b - 1) / b)
#define tomax(a, b) (a = max(a, b))
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

    int n;
    cin >> n;

    vector<ll> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];

    vector<ll> d(n + 1);
    ll sum = 0;
    for(int i = 2; i <= n; i++){
        d[i] = a[i] - a[i - 1];
        if(d[i] > 0) sum += d[i];
    }

    ll x2 = a[1] - sum;
    cout << max(x2 / 2 + sum, a[1] - iceil(x2, 2)) << "\n";

    int q;
    cin >> q;
    while(q--){

        int l, r, x;
        cin >> l >> r >> x;

        if(l != 1){
            if(d[l] > 0) sum -= d[l];
            d[l] += x;
            if(d[l] > 0) sum += d[l];
        }
        else a[1] += x;
        if(r < n){
            if(d[r + 1] > 0) sum -= d[r + 1];
            d[r + 1] -= x;
            if(d[r + 1] > 0) sum += d[r + 1];
        }
//        cerr << a[1] << "\n";
//        printv(d, cerr);

        ll x2 = a[1] - sum;
        cout << max(x2 / 2 + sum, a[1] - iceil(x2, 2)) << "\n";
    }

    return 0;
}