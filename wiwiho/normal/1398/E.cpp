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

int lowbit(int x){
    return x & -x;
}

struct BIT{

    vector<ll> bit;

    explicit BIT(int sz){
        bit.resize(sz + 1);
    }

    void modify(int x, ll v){
        for(; x < bit.size(); x += lowbit(x)){
            bit[x] += v;
        }
    }

    ll query(int x){
        ll ans = 0;
        for(; x > 0; x -= lowbit(x)){
            ans += bit[x];
        }
        return ans;
    }

    int sr(ll v){
        int l = 1, r = bit.size() - 1;
        while(l < r){
            int m = (l + r) / 2;
            if(query(m) < v) l = m + 1;
            else r = m;
        }
        return l;
    }

};

int main(){
    StarBurstStream
    cerr.tie(0);

    int n;
    cin >> n;

    vector<pii> q(n + 1);
    vector<pii> lgt(1), fr(1);
    for(int i = 1; i <= n; i++){
        cin >> q[i].F >> q[i].S;
        if(q[i].F == 0 && q[i].S > 0){
            fr.eb(mp(q[i].S, i));
        }
        if(q[i].F == 1 && q[i].S > 0){
            lgt.eb(mp(q[i].S, i));
        }
    }

    lsort(lgt);
    lsort(fr);

    BIT lbit(n);
    BIT fbit(n);
    BIT lcnt(n);
    BIT fcnt(n);
    int lsz = 0, fsz = 0;

    map<int, vector<int>> fnow, lnow;

    for(int i = 1; i <= n; i++){
//        cerr << "test " << i << "\n";

        int tp = q[i].F, d = q[i].S;
        if(tp == 0){
            if(d > 0){
                int id = lower_bound(iter(fr), mp(d, i)) - fr.begin();
                fnow[d].eb(i);
                fcnt.modify(id, 1);
                fbit.modify(id, d);
                fsz++;
            }
            else{
                int id = lower_bound(iter(fr), mp(-d, fnow[-d].back())) - fr.begin();
                fnow[-d].pob;
                fcnt.modify(id, -1);
                fbit.modify(id, d);
                fsz--;
            }
        }
        else{
            if(d > 0){
                int id = lower_bound(iter(lgt), mp(d, i)) - lgt.begin();
                lnow[d].eb(i);
                lcnt.modify(id, 1);
                lbit.modify(id, d);
                lsz++;
            }
            else{
                int id = lower_bound(iter(lgt), mp(-d, lnow[-d].back())) - lgt.begin();
                lnow[-d].pob;
                lcnt.modify(id, -1);
                lbit.modify(id, d);
                lsz--;
            }
        }
//        for(int i = 1; i <= n; i++){
//            cerr << lbit.query(i) - lbit.query(i - 1) << " ";
//        }
//        cerr << "\n";
//        for(int i = 1; i <= n; i++){
//            cerr << fbit.query(i) - fbit.query(i - 1) << " ";
//        }
//        cerr << "\n";

        if(lsz == 0){
            cout << fbit.query(n) << "\n";
            continue;
        }

        int l = 1, r = min(lsz, fsz);
        while(l < r){
            int m = (l + r + 1) / 2;
            ll tl = lcnt.sr(m);
            ll tf = fcnt.sr(fsz - m + 1);
            ll lv = lbit.query(tl) - lbit.query(tl - 1);
            ll fv = fbit.query(tf) - fbit.query(tf - 1);
            if(lv < fv) l = m;
            else r = m - 1;
        }
//        cerr << l << "\n";

        ll tl = lcnt.sr(l);
        ll tf = fcnt.sr(fsz - l + 1);
//        cerr << tl << " " << tf << "\n";
        ll ans = lbit.query(n) * 2 - lbit.query(tl) + 2 * fbit.query(n) - fbit.query(tf - 1);
        cout << ans << "\n";
    }

    return 0;
}