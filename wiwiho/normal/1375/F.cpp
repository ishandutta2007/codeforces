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

    vector<ll> a(3);
    cin >> a[0] >> a[1] >> a[2];

    cout << "First\n" << flush;

    cout << 100000000000LL << "\n" << flush;

    int x;
    cin >> x;
    if(x == 0) return 0;
    a[x - 1] += 100000000000LL;

    vector<ll> b = a;
    gsort(b);

    cout << 2 * b[0] - b[1] - b[2] << "\n" << flush;

    cin >> x;
    if(x == 0) return 0;
    a[x - 1] += 2 * b[0] - b[1] - b[2];

    b = a;
    gsort(b);

    cout << b[0] - b[1] << "\n" << flush;

    cin >> x;
    //a[x - 1] += b[0] - b[1];
    //printv(a, cout);

    return 0;
}