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

ll getReverse(ll y, ll modNum) {
    return fastPow(y, modNum - 2, modNum) % modNum;
}

ll gcd(ll a, ll b) {
    return (a % b == 0)? b: gcd(b, a%b);
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    get(n);get(m);get(k);
    vector<vector<int>> rowObstacle(n+2), columnObstacle(m+2);

    REP(i, k) {
        get(x);get(y);
        rowObstacle[x].eb(y);
        columnObstacle[y].eb(x);
    }

    // inclusive bound
    ll rowLower = 1, columnLower = 1, rowUpper = n, columnUpper = m;
    int direction = 1;

    ll obstacleCount = 0;
    while (true) {
        int nearest;
        switch (direction) {
            case 0:
                nearest = rowLower-1;
                for (auto& num : columnObstacle[columnLower]) {
                    if (num > nearest && num <= rowUpper) nearest = num;
                }
                obstacleCount += ((ll) (nearest - rowLower + 1)) * (columnUpper - columnLower + 1);
                rowLower = nearest + 1;
                // cout << "position: " << rowLower << "," << columnLower;ln;
                columnLower++;
                break;
            case 1:
                nearest = columnUpper+1;
                for (auto& num : rowObstacle[rowLower]) {
                    if (num < nearest && num >= columnLower) nearest = num;
                }
                obstacleCount += ((ll) (columnUpper + 1 - nearest)) * (rowUpper - rowLower + 1);
                columnUpper = nearest - 1;
                // cout << "position: " << rowLower << "," << columnUpper;ln;
                rowLower++;
                break;
            case 2:
                nearest = rowUpper+1;
                for (auto& num : columnObstacle[columnUpper]) {
                    if (num < nearest && num >= rowLower) nearest = num;
                }
                obstacleCount += ((ll) (rowUpper + 1 - nearest)) * (columnUpper - columnLower + 1);
                rowUpper = nearest - 1;
                // cout << "position: " << rowUpper << "," << columnUpper;ln;
                columnUpper--;
                break;
            case 3:
                nearest = columnLower-1;
                for (auto& num : rowObstacle[rowUpper]) {
                    if (num > nearest && num <= columnUpper) nearest = num;
                }
                obstacleCount += ((ll) (nearest - columnLower + 1)) * (rowUpper - rowLower + 1);
                columnLower = nearest + 1;
                // cout << "position: " << rowUpper << "," << columnLower;ln;
                rowUpper--;
                break;
        }
        // show("direction = ", direction);
        // cout << "row: " << rowLower << " - " << rowUpper << endl;
        // cout << "col: " << columnLower << " - " << columnUpper << endl;
        // show("obstacleCount = ", obstacleCount);

        direction = (direction + 1) % 4;

        
        // char ch;
        // cin >> ch;

        if (rowUpper < rowLower || columnUpper < columnLower) {
            break;
        }
    }

    if (obstacleCount == k) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl; 
    }
}