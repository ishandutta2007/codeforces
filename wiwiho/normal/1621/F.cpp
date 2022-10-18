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


void solve(){

    int n;
    ll a, b, c;
    cin >> n >> a >> b >> c;
    
    int z = 0, o = 0;
    vector<int> seg, side;
    string s;
    cin >> s;
    bool ob = false, zb = false;
    int now = 0;
    for(int i = 0; i < n; i++){
        if(i && s[i] == '1' && s[i - 1] == '0' && zb) seg.eb(now - 1), now = 0;
        if(s[i] == '1') ob = true;
        else if(ob) zb = true;
        if(zb && s[i] == '0') now++;

        if(i == 0) continue;
        if(s[i - 1] == '1' && s[i] == '1') o++;
        if(s[i - 1] == '0' && s[i] == '0') z++;
    }

    if(s[0] == '0'){
        side.eb(0);
    }
    if(n > 1 && s.back() == '0'){
        side.eb(0);
    }
    lsort(side);

    vector<int> seg1 = seg, seg2 = seg;
    if(side.size() >= 1) seg1.eb(side[0]), seg2.eb(side[0]);
    if(side.size() >= 2) seg2.eb(side[1]);
    lsort(seg);
    lsort(seg1);
    lsort(seg2);

    //cerr << z << " " << o << "\n";
    //printv(seg, cerr);

    ll ans = 0;

    { // 101010...
        int tmp = min(z, o);
        ans = max(ans, min(o, tmp + 1) * b + tmp * a);
    }
    { // 010101...
        int tmp = min(z, o);
        ans = max(ans, min(z, tmp + 1) * a + tmp * b);
    }

    if(o){ // 10101..01 0101
        int tmp = min(z, o - 1);
        ll tans = (tmp + 1) * b + tmp * a;
        int sz = 0;

        vector<int> ts;
        if(o - (tmp + 1) >= 2) ts = seg2;
        else if(o - (tmp + 1) >= 1) ts = seg1;
        else ts = seg;
        
        for(int i : ts){
            sz += i;
            if(sz > tmp) break;
            tans += b - c;
        }

        if(z > tmp) tans += a;

        ans = max(ans, tans);
    }

    { // 01010..01 0101
        int tmp = min(z, o);
        ll tans = tmp * b + tmp * a;
        int sz = 0;

        vector<int> ts;
        if(o - (tmp) >= 2) ts = seg2;
        else if(o - (tmp) >= 1) ts = seg1;
        else ts = seg;

        for(int i : seg){
            sz += i;
            if(sz > tmp) break;
            tans += b - c;
        }
        if(z > tmp) tans += a;
        ans = max(ans, tans);
    }

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