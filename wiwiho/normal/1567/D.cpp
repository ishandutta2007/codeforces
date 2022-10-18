
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

int main(){
    StarBurstStream

    int T;
    cin >> T;
    while(T--){

        string s;
        int n;
        cin >> s >> n;
        s = string(10 - (int)s.size(), '0') + s;
        reverse(iter(s));
        vector<int> cnt(10);
        int sum = 0;
        for(int i = 0; i < s.size(); i++){
            cnt[i] = s[i] - '0';
            sum += cnt[i];
        }
//        printv(cnt, cerr);
        while(sum < n){
            for(int i = 1; i < 10; i++){
                if(cnt[i] == 0) continue;
                cnt[i - 1] += 10;
                cnt[i]--;
                sum += 9;
                break;
            }
        }
//        printv(cnt, cerr);

        vector<int> ans(n);

        int p = 0;
        int now = 1;
        for(int i = 0; i < 10; i++){
            while(cnt[i]--){
                ans[p] += now;
                p = (p + 1) % n;
            }
            now *= 10;
        }

        printv(ans, cout);
    }

    return 0;
}