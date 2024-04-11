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

vector<pii> a;
int n;

bool check(int t){
    ll now = 0;
    int i;
    for(i = 0; i < n && a[i].F <= t; i++) now += a[i].F;
    for(; i < n; i++){
        if(now < a[i].F) return false;
        now += a[i].F;
    }
    return true;
}

int main(){
    StarBurstStream

    int T;
    cin >> T;
    while(T--){

        cin >> n;
        a.clear();
        a.resize(n);
        for(int i = 0; i < n; i++){
            cin >> a[i].F;
            a[i].S = i + 1;
        }
        lsort(a);

        int l = 0, r = n - 1;
        while(l < r){
            int m = (l + r) / 2;
            if(check(a[m].F)) r = m;
            else l = m + 1;
        }
        vector<int> ans;
        for(int i = l; i < n; i++) ans.eb(a[i].S);
        lsort(ans);
        cout << ans.size() << "\n";
        printv(ans, cout);

    }

    return 0;
}