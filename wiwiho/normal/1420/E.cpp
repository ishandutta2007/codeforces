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

int main(){
    StarBurstStream

    int n;
    cin >> n;

    vector<int> pos;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        if(a == 1) pos.eb(i);
    }
    if(pos.empty()){
        for(int i = 0; i <= n * (n - 1) / 2; i++) cout << "0 ";
        return 0;
    }

    vector<vector<ll>> dp(n, vector<ll>(n * (n - 1) / 2 + 1, -MAX));

    for(int i = 0; i < n; i++){
        dp[i][abs(pos[0] - i)] = 0;
    }
//    for(int j = 0; j < n; j++) printv(dp[j], cerr);
    for(int i = 0; i < pos.size() - 1; i++){
        vector<vector<ll>> dp2(n, vector<ll>(n * (n - 1) / 2 + 1, -MAX));
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n * (n - 1) / 2; k++){
                if(dp[j][k] == -MAX) continue;

                for(int jj = j + 1; jj < n; jj++){
                    if(k + abs(pos[i + 1] - jj) > n * (n - 1) / 2) continue;
//                    cerr << "tmp " << i << " " << j << ' ' << k << " " << dp[j][k]
//                            << "  " << i + 1 << " " << jj << " " << k + abs(pos[i + 1] - jj) << " " << (j - i) * (jj - j - 1) << "\n";
                    tomax(dp2[jj][k + abs(pos[i + 1] - jj)], dp[j][k] + (j - i) * (jj - j - 1));
                }

            }
        }
        dp = dp2;
//        cerr << "test " << i << "\n";
//        for(int j = 0; j < n; j++) printv(dp[j], cerr);
    }

    vector<ll> ans(n * (n - 1) / 2 + 1);
    for(int i = 0; i < n; i++){
        for(int k = 0; k <= n * (n - 1) / 2; k++){
            if(dp[i][k] == -MAX) continue;
//            cerr << "tmp " << pos.size() - 1 << " " << i << " " << k << " " << dp[i][k] << " "
//                    << (i - (ll)pos.size() + 1) * (n - 1 - i) << " " << i - (ll)pos.size() + 1 << " " << n - 1 - i << "\n";
            ans[k] = max(ans[k], dp[i][k] + (i - (ll)pos.size() + 1) * (n - 1 - i));
        }
    }
    for(int i = 1; i <= n * (n - 1) / 2; i++) ans[i] = max(ans[i - 1], ans[i]);
    printv(ans, cout);

    return 0;
}