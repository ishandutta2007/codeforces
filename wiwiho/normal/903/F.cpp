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
#define iceil(a, b) ((a + b - 1) / b)
#define tomax(a, b) (a = max(a, b))
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}
#define tomin(a, b) (a = min(a, b))

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

int combine(int t1, int t2, int t3, int t4){
    return (t1 << (4 * 3)) + (t2 << (4 * 2)) + (t3 << (4)) + t4;
}

tuple<int, int, int, int> split(int t){
    int t4 = t & 15;
    t >>= 4;
    int t3 = t & 15;
    t >>= 4;
    int t2 = t & 15;
    t >>= 4;
    int t1 = t;
    return mt(t1, t2, t3, t4);
}

int main(){
    StarBurstStream
    freopen("test.txt", "w", stderr);

    int n;
    cin >> n;

    vector<ll> a(4 + 1);
    for(int i = 1; i <= 4; i++) cin >> a[i];

    vector<string> s(4);
    vector<int> t(n + 3);
    for(int i = 0; i < 4; i++){
        cin >> s[i];
        for(int j = 0; j < n; j++){
            if(s[i][j] == '*') t[j] += 1 << i;
        }
    }

//    for(int i = 0; i < n; i++) cerr << bitset<4>(t[i]) << "\n";

    vector<ll> dp(1 << 16, MAX);
    dp[0] = 0;
    for(int i = 0; i < n + 3; i++){
//        cerr << "test " << i << "\n";
        vector<ll> dp2(1 << 16, MAX);
        for(int j = combine(0, 0, 0, 0); j < (1 << 12); j++){
            if(dp[j] == MAX) continue;
            int t1, t2, t3, t4;
            tie(t1, t2, t3, t4) = split(j);
            dp2[combine(t2, t3, t4, t[i])] = dp[j];
        }
        dp = dp2;

        for(int j = (1 << 16) - 1; j >= (1 << 12); j--){
            if(dp[j] == MAX) continue;
            vector<int> now(4);
            tie(now[0], now[1], now[2], now[3]) = split(j);
            for(int y = 0; y < 4; y++){
                for(int k = 1; k <= 4; k++){
                    int mask = ((1 << k) - 1) << y;
//                    cerr << bitset<16>(j) << " " << y << " " << k << " " << bitset<16>(mask) << "\n";
                    mask = 15 ^ mask;
                    vector<int> tnow = now;
                    for(int l = 0; l < k; l++){
                        tnow[l] &= mask;
                    }
                    tomin(dp[combine(tnow[0], tnow[1], tnow[2], tnow[3])], dp[j] + a[k]);
                }
            }
        }

//        for(int j = 0; j < (1 << 16); j++){
//            if(dp[j] == MAX) continue;
//            cerr << bitset<16>(j) << " " << dp[j] << "\n";
//            vector<int> now(4);
//            tie(now[0], now[1], now[2], now[3]) = split(j);
//            for(int i = 0; i < 4; i++) cerr << bitset<4>(now[i]) << "\n";
//        }
    }

    cout << dp[0] << "\n";

    return 0;
}