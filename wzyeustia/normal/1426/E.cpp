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

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int t;
    cin >> t;

    int a1, a2, a3;
        int b1, b2, b3;
        ll minAns, maxAns;
        cin >> a1 >> a2 >> a3;
        cin >> b1 >> b2 >> b3;

        // if (a1 - b1 > 0) {
        //     int remainA1 = a1 - b1;
        //     if (remainA1 - b3 > 0) {
        //         minAns = remainA1 - b3;
        //     }
        //     else {
        //         int remainB3 = b3 - remainA1;
        //         minAns = max(min(remainB3, a2 - b2), 0);
        //     }
        // }
        // else {
        //     int remainB1 = b1 - a1;
        //     if (a3 - b3 > 0) {
        //         if (a3 - b3 - b2 > 0) {
        //             minAns = min(remainB1, a3 - b3 - b2);
        //         }
        //         else {
        //             minAns = 0;
        //         }
        //     }
        //     else {
        //         int remainB3 = b3 - a3;
        //         minAns = min(a2, remainB3);
        //     }
        // }
        minAns = ((ll) max(a2 - b2 - b1, 0) + max(a3 - b3 - b2, 0) + max(a1 - b1 - b3, 0));

        maxAns = ((ll) min(a1, b2)) + min(a2, b3) + min(a3, b1);
        cout << minAns << " " << maxAns << endl;
}