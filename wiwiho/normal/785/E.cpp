
#include <bits/stdc++.h>
#include <bits/extc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0);
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
    vector<int> bit;
    void modify(int x, int v){
        for(; x < bit.size(); x += lowbit(x)){
            bit[x] += v;
        }
    }
    int query(int x){
        int ans = 0;
        for(; x > 0; x -= lowbit(x)){
            ans += bit[x];
        }
        return ans;
    }
};

BIT bit;

struct Info{
    int tm, pos, val, w;
};

ostream& operator<<(ostream& o, Info a){
    return o << '(' << a.tm << ',' << a.pos << ',' << a.val << ',' << a.w << ')';
}

vector<ll> ans;

void cdq1(vector<Info>& v, int l, int r){
    if(l >= r) return;
    int m = (l + r) / 2;
    cdq1(v, l, m);
    cdq1(v, m + 1, r);
//    cerr << "CDQ1 " << l << " " << r << "\n";
//    printv(v, cerr);

    vector<Info> tmp;
    int lp = l, rp = m + 1;

    while(lp <= m && rp <= r){
        if(v[rp].pos <= v[lp].pos){
            tmp.eb(v[rp]);
            ans[v[rp].tm] += v[rp].w * (bit.query((int)bit.bit.size() - 1) - bit.query(v[rp].val));
//            cerr << "ans " << v[rp] << " " << v[rp].w * (bit.query((int)bit.bit.size() - 1) - bit.query(v[rp].val)) << "\n";
            rp++;
        }
        else{
            tmp.eb(v[lp]);
            bit.modify(v[lp].val, v[lp].w);
            lp++;
        }
    }
    while(lp <= m){
        tmp.eb(v[lp]);
        bit.modify(v[lp].val, v[lp].w);
        lp++;
    }
    while(rp <= r){
        tmp.eb(v[rp]);
        ans[v[rp].tm] += v[rp].w * (bit.query((int)bit.bit.size() - 1) - bit.query(v[rp].val));
//        cerr << "ans " << v[rp] << " " << v[rp].w * (bit.query((int)bit.bit.size() - 1) - bit.query(v[rp].val)) << "\n";
        rp++;
    }
//    printv(tmp, cerr);

    for(int i = l; i <= m; i++){
        bit.modify(v[i].val, -v[i].w);
    }

    for(int i = l; i <= r; i++) v[i] = tmp[i - l];
}

void cdq2(vector<Info>& v, int l, int r){
    if(l >= r) return;
    int m = (l + r) / 2;
    cdq2(v, l, m);
    cdq2(v, m + 1, r);
//    cerr << "CDQ2 " << l << " " << r << "\n";
//    printv(v, cerr);

    vector<Info> tmp;
    int lp = l, rp = m + 1;

    while(lp <= m && rp <= r){
        if(v[rp].pos >= v[lp].pos){
            tmp.eb(v[rp]);
//            cerr << "ans " << v[rp] << " " << v[rp].w * bit.query(v[rp].val - 1) << "\n";
            ans[v[rp].tm] += v[rp].w * bit.query(v[rp].val - 1);
            rp++;
        }
        else{
            tmp.eb(v[lp]);
            bit.modify(v[lp].val, v[lp].w);
            lp++;
        }
    }
    while(lp <= m){
        tmp.eb(v[lp]);
        bit.modify(v[lp].val, v[lp].w);
        lp++;
    }
    while(rp <= r){
        tmp.eb(v[rp]);
        ans[v[rp].tm] += v[rp].w * bit.query(v[rp].val - 1);
//        cerr << "ans " << v[rp] << " " << v[rp].w * bit.query(v[rp].val - 1) << "\n";
        rp++;
    }

//    printv(tmp, cerr);
    for(int i = l; i <= m; i++){
        bit.modify(v[i].val, -v[i].w);
    }

    for(int i = l; i <= r; i++) v[i] = tmp[i - l];
}

int main(){
    StarBurstStream
//    freopen("test.txt", "w", stderr);

    int n, q;
    cin >> n >> q;

    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) a[i] = i;

    vector<Info> v;
    for(int i = 1; i <= n; i++){
        v.eb(Info({i, i, a[i], 1}));
    }

    for(int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r;
        v.eb(Info({n + 2 * i + 1, l, a[l], -1}));
        v.eb(Info({n + 2 * i + 2, r, a[r], -1}));
        swap(a[l], a[r]);
        v.eb(Info({n + 2 * i + 1, l, a[l], 1}));
        v.eb(Info({n + 2 * i + 2, r, a[r], 1}));
    }

    ans.resize(1 + n + 2 * q);
    bit.bit.resize(n + 1);

    sort(iter(v), [&](Info a, Info b){
        return a.tm == b.tm ? a.pos > b.pos : a.tm < b.tm;
    });
    cdq1(v, 0, (int)v.size() - 1);
    sort(iter(v), [&](Info a, Info b){
        return a.tm == b.tm ? a.pos < b.pos : a.tm < b.tm;
    });
    cdq2(v, 0, (int)v.size() - 1);

    for(int i = 1; i <= n + 2 * q; i++){
        ans[i] += ans[i - 1];
    }
//    printv(ans, cerr);
    for(int i = 0; i < q; i++){
        cout << ans[n + 2 * i + 2] << "\n";
    }

    return 0;
}