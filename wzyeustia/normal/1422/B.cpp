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


int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    get(t);
    REP(I, t) {
        get(n);get(m);
        vector<vector<int>> arr(n, vector<int>(m));
        REP(i, n) {
            REP(j, m) {
                cin >> arr[i][j];
            }
        }

        ll ans = 0;

        for (int i = 0; i < (n + 1) / 2; i++) {
            for (int j = 0; j < (m + 1) / 2; j++) {
                int final, count = 4;
                int sum = 0;
                vector<int> vec;
                if (i == n / 2) {
                    if (j == m / 2) {
                        continue;
                    }
                    else {
                        count = 2;
                        sum = arr[i][j] + arr[i][m-1-j];
                        final = sum / 2;
                        ans += abs(final - arr[i][j]) + abs(final - arr[i][m-1-j]);
                    }
                }
                else {
                    if (j == m / 2) {
                        count = 2;
                        sum = arr[i][j] + arr[n-1-i][j];
                        final = sum / 2;
                        ans += abs(final - arr[i][j]) + abs(final - arr[n-1-i][j]);
                    }
                    else {
                        sum = arr[i][j] + arr[n-1-i][j] + arr[i][m-1-j] + arr[n-1-i][m-1-j];

                        vec.eb(arr[i][j]);vec.eb(arr[n-1-i][j]);vec.eb(arr[i][m-1-j]);vec.eb(arr[n-1-i][m-1-j]);
                        sort(vec.begin(), vec.end());
                        final = vec[1];
                        ans += abs(final - arr[i][j]) + abs(final - arr[n-1-i][j]) + abs(final - arr[i][m-1-j]) + abs(final - arr[n-1-i][m-1-j]);
                    }
                }

            }
        }

        cout << ans << endl;
    }
}