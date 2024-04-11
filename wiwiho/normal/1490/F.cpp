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
        map<int, int> acnt;
        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            acnt[a]++;
        }

        vector<int> cnt(n + 1);
        for(auto i : acnt) cnt[i.S]++;
        vector<int> suf(n + 2), pre(n + 1), sufc(n + 2);
        for(int i = 1; i <= n; i++) pre[i] = cnt[i] * i + pre[i - 1];
        for(int i = n; i >= 1; i--){
            suf[i] = cnt[i] * i + suf[i + 1];
            sufc[i] = cnt[i] + sufc[i + 1];
        }
//        printv(cnt, cerr);
//        printv(pre, cerr);
//        printv(suf, cerr);
//        printv(sufc, cerr);

        int ans = MAX;
        for(int i = 0; i <= n; i++){
            int t = (i ? pre[i - 1] : 0) + suf[i + 1] - sufc[i + 1] * i;
//            cerr << i << " " << t << "\n";
            ans = min(ans, t);
        }
        cout << ans << "\n";

    }

    return 0;
}