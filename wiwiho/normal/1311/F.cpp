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

template<typename T>
struct BIT{

private:
    vector<T> bit;
    int lowbit(int x){
        return x & (-x);
    }

public:
    explicit BIT(int sz){
        bit.resize(sz + 1);
    }

    void modify(int x, T v){
        for(; x < bit.size(); x += lowbit(x)) bit[x] += v;
    }

    T get(int x){
        T ans = T();
        for(; x; x -= lowbit(x)) ans += bit[x];
        return ans;
    }
};

int main(){
    StarBurstStream

    int n;
    cin >> n;

    vector<pll> x(n + 1);
    vector<pll> t(n);

    BIT<ll> pos(n), cnt(n);

    for(int i = 1; i <= n; i++) cin >> x[i].F;
    for(int i = 1; i <= n; i++) cin >> x[i].S;
    lsort(x);
    for(int i = 1; i <= n; i++){
        pos.modify(i, x[i].F);
        cnt.modify(i, 1);
        t[i - 1] = mp(x[i].S, i);
    }

    gsort(t);

    ll ans = 0;
    for(int i = 0; i < n; i++){
        ll p = t[i].S;
        ans += cnt.get(p - 1) * x[p].F - pos.get(p - 1);
        cnt.modify(p, -1);
        pos.modify(p, -x[p].F);
    }

    cout << ans << "\n";

    return 0;
}