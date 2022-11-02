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

int bfs(vector<int>::iterator start, vector<int>::iterator end, int crtVal, int crtLevel) {
    if (end - start <= 1) return 0;
    // cout << "end - start = " << end - start << endl;
    vector<int>::iterator bound = lower_bound(start, end, crtVal);

    int lCost = bfs(start, bound, crtVal - crtLevel / 2, crtLevel / 2);
    int rCost = bfs(bound, end, crtVal + crtLevel / 2, crtLevel / 2);
    return min(lCost + max(end - bound - 1, (ptrdiff_t)0), rCost + max(bound - start - 1, (ptrdiff_t) 0));
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr(n);
    REP(i, n)
        cin >> arr[i];

    sort(arr.begin(), arr.end());

    cout << bfs(arr.begin(), arr.end(), 1 << 30, 1 << 30) << endl;
    // int cost[50];
    // REP(i, n) {
        
    // }

    //Main program
}