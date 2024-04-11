#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

#ifdef OI_DEBUG
template<char endch, typename T>
void log_impl(T&& val) { cout << val << endch; }
template<char endch, typename T, typename... Ts>
void log_impl(T &&val, Ts &&...vals) {
    cout << val << ' ';
    log_impl<endch>(vals...);
}
#define logs log_impl<' '>
#define logln log_impl<'\n'>
#else
template<typename... Ts> void do_nothing(Ts &&...vals) {}
#define logs do_nothing
#define logln do_nothing
#endif // OI_DEBUG

#define MKPR make_pair
#define ALL(c) begin(c), end(c)
#define ALLn(arr, n) arr, arr+n
#define FILL0(arr) memset(arr, 0, sizeof(arr))
#define FILL1(arr) memset(arr, -1, sizeof(arr))

typedef unsigned long long ULL;
typedef unsigned int Uint;
typedef unsigned char Byte;


constexpr ll MOD = 1000000007;
constexpr int INF = 0x7f7f7f7f;
constexpr double EPS = 1e-8;
//Common variables

ll myPow(ll num) {
    if (num <= 0)
        return 1;
    if (num == 1)
        return 3;
    else {
        return (myPow(num / 2) * myPow(num - num / 2)) % MOD;
    }
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int n;
    cin >> n;

    ll modNum = 1e9+7;

    string str;
    cin >> str;

    int sumCountQ = 0;
    // vector<int> countQ;
    REP (i, n) {
        if (str[i] == '?')
            sumCountQ++;
        // countQ.eb(crtCountQ);
    }

    ll dp[4][4];
    FILL0(dp);
    dp[0][0] = 1;

    REP (i, n) {
        switch (str[i])
        {
        case 'a': 
            dp[1][0] = (dp[1][0] + dp[0][0]) % modNum;
            break;
        case 'b':
            dp[2][0] = (dp[2][0] + dp[1][0]) % modNum;
            dp[2][1] = (dp[2][1] + dp[1][1]) % modNum;
            break;
        case 'c':
            ROF (j, 2, 0) {
                dp[3][j] = (dp[3][j] + dp[2][j]) % modNum;
            }
            break;
        case '?':
            ROF (k, 3, 1) {
                FOR (j, 1, k) {
                    dp[k][j] = (dp[k][j] + dp[k - 1][j - 1]) % modNum;
                }
            }
            break;
        default:
            cout << "What???" << endl;
            break;
        }
        // FOR (j, 1, 3) {
        //     FOR (k, 0, 3) {
        //         cout << dp[j][k] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
            
        
    }

    ll ans = 0;
    FOR (i, 0, 3) {
        ans = (ans + dp[3][i] * myPow(sumCountQ - i)) % modNum;
    }
    cout << ans << endl;
    
}