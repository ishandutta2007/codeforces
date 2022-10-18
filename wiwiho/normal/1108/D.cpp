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
#define iceil(a, b) (((a) + (b) - 1) / (b))
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
    string s;
    cin >> s;

    vector<vector<pii>> dp(n, vector<pii>(3, mp(n + 1, -1)));
    string c = "RGB";

    for(int i = 0; i < 3; i++){
        if(s[0] == c[i]) dp[0][i] = mp(0, -1);
        else dp[0][i] = mp(1, -1);
    }

    for(int i = 1; i < n; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                if(j == k) continue;
                dp[i][j] = min(dp[i][j], mp(dp[i - 1][k].F + (s[i] != c[j]), k));
            }
        }
    }

//    for(int i = 0; i < n; i++) printv(dp[i], cerr);

    pii ans = min({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
    int now = min_element(iter(dp[n - 1])) - dp[n - 1].begin();
    string anss;
    for(int i = n - 1; i >= 0; i--){
        anss += c[now];
        now = dp[i][now].S;
    }
    reverse(iter(anss));

    cout << ans.F << "\n" << anss << "\n";

    return 0;
}