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

void dfs(vector<string> &graph, int i, int j) {
    if (graph[i][j] == '.') return;
    graph[i][j] = '.';
    if (i > 0) dfs(graph, i-1, j);
    if (j > 0) dfs(graph, i, j-1);
    if (i < graph.size()-1) dfs(graph, i+1, j);
    if (j < graph[0].length()-1) dfs(graph, i, j+1);
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    bool success = true;
    int ans = 0x7f7f7f7f;
    bool horizontalEmpty = false;
    bool verticalEmpty = false;

    get(n);get(m);
    vector<string> graph(n);
    getArr(graph, n);

    REP(i, n) {
        int j = 0;
        while (j < m && graph[i][j] == '.') j++;

        if (j == m) {
            horizontalEmpty = true;
        }
        while (j < m && graph[i][j] == '#') j++;
        while (j < m && graph[i][j] == '.') j++;
        if (j != m) {
            success = false;
            break;
        }
    }

    REP(j, m) {
        int i = 0;
        while (i < n && graph[i][j] == '.') i++;

        if (i == n) {
            verticalEmpty = true;
        }
        while (i < n && graph[i][j] == '#') i++;
        while (i < n && graph[i][j] == '.') i++;
        if (i != n) {
            success = false;
            break;
        }
    }

    if (horizontalEmpty ^ verticalEmpty)
        success = false;

    ans = 0;
    REP(i, n) {
        REP(j, m) {
            if (graph[i][j] == '#') {
                ans++;
                dfs(graph, i, j);
            }
        }
    }

    if (success) {
        cout << ans << endl;
    }
    else {
        cout << -1 << endl;
    }
    //Main program
}