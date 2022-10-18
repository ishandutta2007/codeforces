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

int lowbit(int x){
    return x & -x;
}

struct BIT{
    vector<ll> bit;

    explicit BIT(int n){
        bit.resize(n + 1);
    }

    void modify(int x, ll v){
        for(; x < bit.size(); x += lowbit(x)){
            bit[x] += v;
            bit[x] %= MOD;
        }
    }

    ll query(int x){
        ll ans = 0;
        for(; x > 0; x -= lowbit(x)){
            ans += bit[x];
            ans %= MOD;
        }
        return ans;
    }
};

struct Discr{
    vector<int> t;
    Discr(vector<int> &v): t(v){
        lsort(t);
        uni(t);
    }
    int operator[](int v){
        return lower_bound(iter(t), v) - t.begin() + 1;
    }
};

int n;
vector<int> a;
vector<ll> precnt;

ll calc1(){
    vector<int> t = a;
    t.erase(t.begin());
    Discr discr(t);

    BIT cntbit(n), sumbit(n);
    vector<ll> cnt(n + 1), sum(n + 1);

    for(int i = 1; i <= n; i++){
        int v = discr[a[i]];
        cnt[i] = cntbit.query(v - 1) + 1;
        sum[i] = sumbit.query(v - 1) + cnt[i];
        cnt[i] %= MOD;
        sum[i] %= MOD;
        cntbit.modify(v, cnt[i]);
        sumbit.modify(v, sum[i]);
        //cerr << i << " " << v << "\n";
    }
    //printv(sum, cerr);
    //for(int i = 1; i <= n; i++) cerr << sumbit.query(i) << " ";
    //cerr << "\n";

    precnt = cnt;
    return sumbit.query(n);
}

ll calc2(vector<int>& pos){

    vector<int> t;
    for(int i : pos) t.eb(a[i]);
    Discr discr(t);
    int m = pos.size();
    
    BIT cntbit(m);
    vector<ll> cnt(m);

    for(int i = m - 1; i >= 0; i--){
        int v = discr[a[pos[i]]];
        if(i == m - 1) cnt[i] = 1;
        else cnt[i] = cntbit.query(m) - cntbit.query(v);
        topos(cnt[i]);
        cntbit.modify(v, cnt[i]);
    }

    /*cerr << "calc ";
    printv(pos, cerr);
    printv(cnt, cerr);
    cerr << "calc ok\n";*/

    ll ans = 0;
    for(int i = 0; i < m; i++){
        ans += precnt[pos[i]] * cnt[i] % MOD;
        ans %= MOD;
    }

    return ans;
}

void solve(){
    
    cin >> n;
    a.clear();
    precnt.clear();

    vector<pii> pos;
    a.resize(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        pos.eb(mp(a[i], i));
    }
    sort(iter(pos), [](pii a, pii b){ return a.F == b.F ? a.S < b.S : a.F > b.F; });

    vector<vector<int>> g;
    int lst = -1;
    for(pii i : pos){
        if(i.S > lst){
            g.eb();
            lst = i.S;
        }
        g.back().eb(i.S);
    }

    ll ans = calc1();
    //cerr << "initial " << ans << "\n";
    //printv(precnt, cerr);
    for(auto& i : g){
        lsort(i);
        //cerr << "g ";
        //printv(i, cerr);
        ll tmp = calc2(i);
        //cerr << tmp << "\n";
        ans -= tmp;
        ans %= MOD;
    }
    topos(ans);

    cout << ans << "\n";

}

int main(){
    StarBurstStream

    int T;
    cin >> T;
    while(T--){
        solve();
    }

    return 0;
}