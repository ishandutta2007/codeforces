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
#define tomax(a, b) ((a) = max((a), (b)))
#define tomin(a, b) ((a) = min((a), (b)))
#define topos(a) ((a) = (((a) % MOD + MOD) % MOD))
#define uni(a) a.resize(unique(iter(a)) - a.begin())
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}

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

ll ifloor(ll a, ll b){
    if(b < 0) a *= -1, b *= -1;
    if(a < 0) return (a - b + 1) / b;
    else return a / b;
}

ll iceil(ll a, ll b){
    if(b < 0) a *= -1, b *= -1;
    if(a > 0) return (a + b - 1) / b;
    else return a / b;
}

ll calc(ll l, ll r){
    return (l + r) * (r - l + 1) / 2;
}

vector<int> a;

vector<int> BIT;

int lowbit(int x){
    return x & -x;
}

void modify(int x, int v){
    for(; x < BIT.size(); x += lowbit(x)){
        BIT[x] += v;
    }
}

int query(int x){
    int ans = 0;
    for(; x > 0; x -= lowbit(x)){
        ans += BIT[x];
    }
    return ans;
}

vector<int> tq;

int ask(int x){
    if(tq[x] != -1) return tq[x] + query(x);
    cout << "? 1 " << x << "\n" << flush;
    int r;
    cin >> r;
    tq[x] = r - query(x);
    return r;
}

void ans(int x){
    cout << "! " << x << "\n" << flush;
    modify(x, 1);
}

int main(){
    StarBurstStream

    int n, T;
    cin >> n >> T;

    BIT.resize(n + 1);
    tq.resize(n + 1, -1);

    int sz = 32;
    int cnt = iceil(n, 32);

    int k;
    cin >> k;

    for(int i = sz; i <= n; i += sz){
        ask(i);
    }

    for(int tt = 1; tt <= T; tt++){
        if(tt != 1) cin >> k;

        int l = 1, r = cnt;
        while(l < r){
            int m = (l + r) / 2;
            if(m * sz - ask(m * sz) < k) l = m + 1;
            else r = m;
        }

        int tmp = l;
        r = tmp * sz;
        l = r - sz + 1;
        r = min(r, n);

        while(l < r){
//            cerr << l << " " << r << "\n";
            int m = (l + r) / 2;
            if(m - ask(m) < k) l = m + 1;
            else r = m;
        }

        ans(l);
    }

    return 0;
}