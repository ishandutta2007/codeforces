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

int main(){
    StarBurstStream

    int T;
    cin >> T;
    while(T--){

        int n;
        cin >> n;

        vector<int> b(n + 2);
        b[n + 1] = MAX;
        vector<bool> tmp(2 * n + 1);
        vector<int> t(1);
        for(int i = 1; i <= n; i++) cin >> b[i], tmp[b[i]] = true;
        for(int i = 1; i <= 2 * n; i++){
            if(!tmp[i]) t.eb(i);
        }
        t.eb(MAX);

        vector<int> mx(n + 2), mn(n + 2);
        mx[0] = mx[n + 1] = MAX;
        for(int i = 1; i <= n; i++){
            int pos = lower_bound(iter(t), b[i]) - t.begin();
//            cerr << "mx " << b[i] << " " << pos << "\n";
            mx[i] = n + i - pos;
            mx[i] = min(mx[i], mx[i - 1]);
        }
        mx[n + 1] = mx[n];
        for(int i = n; i >= 1; i--){
            int pos = lower_bound(iter(t), b[i]) - t.begin() - 1;
//            cerr << "mn " << b[i] << " " << pos << "\n";
            mn[i] = i - pos;
//            if(mn[i] == n) mn[i] = MAX;
            mn[i] = max(mn[i], mn[i + 1]);
        }
        mn[0] = mn[1];
//        printv(mn, cerr);
//        printv(mx, cerr);

        int ans = 0;
        for(int x = 0; x <= n; x++){
//            cerr << x << " " << mn[x + 1] << " " << mx[x] << "\n";
            if(mn[x + 1] <= x && x <= mx[x]) ans++;
        }
        cout << ans << "\n";

    }

    return 0;
}