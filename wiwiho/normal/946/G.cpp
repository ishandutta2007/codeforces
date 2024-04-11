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
const ll MAX = 100000000;

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

struct owo{
    map<int, int> s;
    map<int, int> t;

    void modify(int pos, int v){
        auto it = s.upper_bound(pos);
        if(it != s.end() && it->S <= v) return;
        while(it != s.begin() && prev(it)->S >= v){
            it--;
            t.erase(it->S);
            it = s.erase(it);
        }
        if(s.find(pos) == s.end()){
            s[pos] = v;
            t[v] = pos;
        }
    }

    int query(int pos){
        auto it = s.lower_bound(pos);
        if(it == s.end()) return MAX;
        else return it->S;
    }

    int upper_bound(int v){
        auto it = t.upper_bound(v);
        if(it == t.begin()) return 0;
        else return prev(it)->S + 1;
    }
};

int main(){
    StarBurstStream

    int n;
    cin >> n;

    owo dpo;
    owo dp1;
    owo dp2;
    dp1.modify(0, -MAX);
    dp2.modify(0, -MAX);
    int lstp = -1, lst = -1;

    int ans = 0;
    for(int i = 1; i <= n; i++){
        int a;
        cin >> a;
        a -= i;

        int pos = dp2.upper_bound(a);
        dp2.modify(pos, a);
        ans = max(ans, pos);

        pos = dpo.upper_bound(a + 1);
        dp2.modify(pos, a);
        ans = max(ans, pos);

        if(lstp != -1) dpo.modify(lstp, lst);

        pos = dp1.upper_bound(a);
        dp1.modify(pos, a);
        ans = max(ans, pos);
        lstp = pos; lst = a;

        /*cerr << "test " << i << "\n";
        printv(dp1.s, cerr);
        printv(dp2.s, cerr);
        printv(dpo.s, cerr);*/
    }

    cout << max(0, n - ans - 1) << "\n";

    return 0;
}