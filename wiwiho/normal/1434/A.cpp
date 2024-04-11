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

int main(){
    StarBurstStream

    vector<ll> a(6);
    for(int i = 0; i < 6; i++) cin >> a[i];
    int n;
    cin >> n;

    vector<pll> tmp;
    for(int i = 0; i < n; i++){
        ll b;
        cin >> b;
        for(int j = 0; j < 6; j++) tmp.eb(mp(b - a[j], i));
    }
    lsort(tmp);
//    printv(tmp, cerr);

    vector<int> lst(n, -1);
    set<pll> st;
    ll ans = 1LL << 60;
    for(int j = 0; j < tmp.size(); j++){
        auto i = tmp[j];
        if(lst[i.S] != -1) st.erase(mp(tmp[lst[i.S]].F, i.S));
        st.insert(i);
        lst[i.S] = j;
        if(st.size() == n) ans = min(ans, i.F - st.begin()->F);
//        cerr << j << "  ";
//        printv(st, cerr);
    }
    cout << ans << "\n";

    return 0;
}