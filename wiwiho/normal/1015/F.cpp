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
    int m = s.size();
    s = ' ' + s;

    vector<int> len0(m + 1, s[1] == '('), len1(m + 1, s[1] == ')');
    for(int i = 2; i <= m; i++){
        for(int j = i; j <= m; j++){
            bool ok = true;
            for(int k = 1; k <= j - i + 1; k++){
                if(s[k] != s[i + k - 1]) ok = false;
            }
            if(!ok) continue;
//            cerr << s << " " << i << " " << j << "\n";
            if(s[j - i + 2] == '(') len0[j] = max(len0[j], j - i + 2);
            if(s[j - i + 2] == ')') len1[j] = max(len1[j], j - i + 2);
        }
    }
//    printv(len0, cerr);
//    printv(len1, cerr);

    vector<vector<vector<ll>>> dp0(2 * n + 1, vector<vector<ll>>(n + 1, vector<ll>(m + 1)));
    vector<vector<ll>> dp1(2 * n + 1, vector<ll>(n + 1));
    dp0[0][0][0] = 1;
    for(int i = 0; i < 2 * n; i++){
        for(int j = 0; j <= n; j++){

            for(int k = 0; k <= m; k++){
                if(k == m){
                    dp1[i][j] += dp0[i][j][k];
                    dp1[i][j] %= MOD;
                    continue;
                }
                if(j){
                    if(s[k + 1] == ')') dp0[i + 1][j - 1][k + 1] += dp0[i][j][k], dp0[i + 1][j - 1][k + 1] %= MOD;
                    else dp0[i + 1][j - 1][len1[k]] += dp0[i][j][k], dp0[i + 1][j - 1][len1[k]] %= MOD;
                }
                if(j < n){
                    if(s[k + 1] == '(') dp0[i + 1][j + 1][k + 1] += dp0[i][j][k], dp0[i + 1][j + 1][k + 1] %= MOD;
                    else dp0[i + 1][j + 1][len0[k]] += dp0[i][j][k], dp0[i + 1][j + 1][len0[k]] %= MOD;
                }
            }

            if(j) dp1[i + 1][j - 1] += dp1[i][j], dp1[i + 1][j - 1] %= MOD;
            if(j < n) dp1[i + 1][j + 1] += dp1[i][j], dp1[i + 1][j + 1] %= MOD;
//
//            cerr << i << " " << j << " " << dp1[i][j] << "  ";
//            printv(dp0[i][j], cerr);

        }
    }

    dp1[2 * n][0] += dp0[2 * n][0][m];
    dp1[2 * n][0] %= MOD;

//    for(int j = 0; j <= n; j++){
//        int i = 2 * n;
//        cerr << i << " " << j << " " << dp1[i][j] << "  ";
//        printv(dp0[i][j], cerr);
//    }

    cout << dp1[2 * n][0] << "\n";

    return 0;
}