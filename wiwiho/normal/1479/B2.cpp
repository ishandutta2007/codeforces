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

    int n;
    cin >> n;
//    n = 20;

    vector<int> a;
    int lst = -1;
//    srand(123);
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
//        t = rand() % n + 1;
        if(lst != t) a.eb(t);
        lst = t;
    }
    if(n == 1){
        cout << "1\n";
        return 0;
    }

    n = a.size();
    vector<ll> dp(n + 1, MAX);
    multiset<ll> mn;
    for(int i = 1; i <= n; i++) mn.insert(MAX);
    ll all = 0;
    dp[a[0]] = 2;
    mn.erase(mn.find(MAX));
    mn.insert(2);

//    printv(dp, cerr);
    for(int i = 2; i < n; i++){
        ll tmp = dp[a[i]];
        tmp = min(tmp, *mn.begin() + 1);
        tmp--;
        mn.erase(mn.find(dp[a[i - 1]]));
        dp[a[i - 1]] = min(dp[a[i - 1]], tmp);
        mn.insert(dp[a[i - 1]]);
        all++;
//        printv(dp, cerr);
    }
    cout << *mn.begin() + all << "\n";

    return 0;
}