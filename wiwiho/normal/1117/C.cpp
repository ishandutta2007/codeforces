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

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int x = x2 - x1, y = y2 - y1;

    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<ll> l(n + 1), r(n + 1), d(n + 1), u(n + 1);
    s = " " + s;
    for(int i = 1; i <= n; i++){
        if(s[i] == 'L') l[i]++;
        else if(s[i] == 'R') r[i]++;
        else if(s[i] == 'U') u[i]++;
        else d[i]++;
        l[i] += l[i - 1];
        r[i] += r[i - 1];
        u[i] += u[i - 1];
        d[i] += d[i - 1];
    }
//    printv(l, cerr);
//    printv(r, cerr);
//    printv(u, cerr);
//    printv(d, cerr);

    ll lr = 1, rr = (1LL << 55);
    bool ans = false;
    while(lr < rr){
        ll m = (lr + rr) / 2;
        ll tmp = abs(m / n * (u[n] - d[n]) + u[m % n] - d[m % n] - y) + abs(m / n * (r[n] - l[n]) + r[m % n] - l[m % n] - x);
//        cerr << m << " " << tmp << " " << m / n * (u[n] - d[n]) + u[m % n] - d[m % n] << " " << abs(m / n * (r[n] - l[n]) + r[m % n] - l[m % n] - x) << "\n";
        if(tmp <= m) rr = m, ans = true;
        else lr = m + 1;
    }
    ll m = lr;
    ll tmp = abs(m / n * (u[n] - d[n]) + u[m % n] - d[m % n] - y) + abs(m / n * (r[n] - l[n]) + r[m % n] - l[m % n] - x);
    if(tmp <= m) cout << lr << "\n";
    else cout << "-1\n";
//    cerr << ans << "\n";

    return 0;
}