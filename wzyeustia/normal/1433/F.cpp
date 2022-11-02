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

#define ln cout << endl;
#define show(str, x) cout << str << x; ln
#define showArr(str, arr, size) cout << str; ln; REP(test, size) {cout << arr[test] << " ";} ln

#define get(x) int x; cin >> x
#define getArr(arr, n) REP(i, n) {cin >> arr[i];}

typedef unsigned long long ULL;
typedef unsigned int Uint;
typedef unsigned char Byte;


constexpr ll MOD = 1000000007;
constexpr int INF = 0x7f7f7f7f;
constexpr double EPS = 1e-8;
//Common variables

ll fastPow(ll num, ll exp, ll modNum) {
    if (exp == 0) return 1;
    if (exp == 1) return num;
    else {
        ll half = fastPow(num, exp/2, modNum) % modNum;
        if (exp % 2 == 1) {
            return (((half * half) % modNum) * num) % modNum;
        }
        else {
            return (half * half) % modNum;
        }
    }
}

ll fastPow(ll num, ll exp) {
    if (exp == 0) return 1;
    if (exp == 1) return num;
    else {
        ll half = fastPow(num, exp/2);
        if (exp % 2 == 1) {
            return (((half * half)) * num);
        }
        else {
            return (half * half);
        }
    }
}
 
ll getReverse(ll y, ll modNum) {
    return fastPow(y, modNum - 2, modNum) % modNum;
}
 
ll gcd(ll a, ll b) {
    return (a % b == 0)? b: gcd(b, a%b);
}

void dfs(vector<ll> &seq, vector<vector<ll>> child, int i) {
    for (auto& adj : child[i]) {
        dfs(seq, child, adj);
    }
    seq.emplace_back(i);
}

int lowbit(int x)
{
    return x&(-x);
}

void edit(vector<int> &BIT, int k, int n) {
    // cout << "editing..." << endl;
    // cout << "k = " << k << endl;
    if (k == 0) return;

    for (int i = k; i <= n; i += lowbit(i)) {
        BIT[i]++;
    }
}

int check(vector<int> &BIT, int k) {
    int ans = 0;
    for (int i = k; i > 0; i -= lowbit(i)) {
        ans += BIT[i];
    }
    return ans;
}

int countDivisor(int n, int k) {
    int count = 0;
    while (n % k == 0) {
        count++;
        n /= k;
    }
    return count;
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    get(n);get(m);get(k);
    vector<vector<int>> graph(n, vector<int>(m)), maximum(n, vector<int>(k, 0));
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(k, vector<int>(m/2+1, -(0x7f7f7f))));


    REP(i, n) {
        dp[i][0][0] = 0;
        REP(j, m) {
            cin >> graph[i][j];
            for (int t = m/2; t > 0; t--) {
                REP(s, k) {
                    int transit = (graph[i][j]%k);
                    dp[i][s][t] = max(dp[i][s][t], dp[i][(s-transit+k)%k][t-1] + graph[i][j]);
                    maximum[i][s] = max(maximum[i][s], dp[i][s][t]);
                }
            }
        }
    }

    // cout << "dp:" << endl;
    // REP(i, n) {
    //     REP(j, k) {
    //         REP(t, m/2+1) {
    //             cout << dp[i][j][t] << " ";
    //         }ln;
    //     }ln;
    // }

    // cout << "maximum:" << endl;
    // REP(i, n) {
    //     REP(j, k) {
    //         cout << maximum[i][j] << " ";
    //     }
    //     ln;
    // }    

    vector<vector<int>> dp2(n+1, vector<int>(k, -(0x7f7f7f)));
    dp2[0][0] = 0;
    for(int i = 1; i <= n; i++) {
        REP(j, k) {
            int transit = maximum[i-1][j] % k;
            REP(s, k) {
                dp2[i][s] = max(dp2[i][s], dp2[i-1][(s-transit+k)%k] + maximum[i-1][j]);
            }
        }
    }

    // cout << "dp2:" << endl;
    // REP(i, n+1) {
    //     REP(j, k) {
    //         cout << dp2[i][j] << " ";
    //     }ln;
    // }ln;

    cout << dp2[n][0] << endl;
}