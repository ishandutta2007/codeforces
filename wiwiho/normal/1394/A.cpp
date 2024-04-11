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
#define iceil(a, b) (((a) + (b) - 1) / (b))
#define tomax(a, b) ((a) = max((a), (b)))
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

    int n, d, m;
    cin >> n >> d >> m;

    vector<ll> a(1), b(1);
    ll sum = 0;
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        sum += t;
        if(t > m) b.eb(t);
        else a.eb(t);
    }

    sort(a.begin() + 1, a.end(), greater<>());
    sort(b.begin() + 1, b.end(), greater<>());
    for(int i = 1; i < a.size(); i++) a[i] += a[i - 1];
    for(int i = 1; i < b.size(); i++) b[i] += b[i - 1];

    int acnt = a.size() - 1, bcnt = b.size() - 1;
//    printv(b, cerr);
//    printv(a, cerr);

    ll ans = 0;
    for(int i = 0; i <= n; i++){
        int cnt = iceil(i, d);
        if(cnt > bcnt || cnt + i < bcnt || cnt + i > n) continue;
//        cerr << i << " " << cnt << " " << acnt - (i - (bcnt - cnt)) << "\n";
        ans = max(ans, b[cnt] + a[acnt - (i - (bcnt - cnt))]);
    }
    for(int i = 0; i <= n; i++){
        if(i % d) continue;
        int cnt = i / d + 1;
        if(cnt > bcnt || cnt + i < bcnt || cnt + i > n) continue;
//        cerr << i << " " << cnt << " " << acnt - (i - (bcnt - cnt)) << "\n";
        ans = max(ans, b[cnt] + a[acnt - (i - (bcnt - cnt))]);
    }
    cout << ans << "\n";

    return 0;
}