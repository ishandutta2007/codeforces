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

struct point {
    int index;
    vector<int> adj = vector<int>();
    int aDist = INF, bDist = INF, cDist = INF;
};

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    bool success = true;
    int ans = 0x7f7f7f7f;
    bool horizontalEmpty = false;
    bool verticalEmpty = false;

    get(t);
    REP(I, t) {
        get(n);get(m);get(a);get(b);get(c);

        vector<ll> prices(m);
        getArr(prices, m);
        sort(prices.begin(), prices.end());
        vector<ll> prefix(m+1, (ll)0);
        FOR(i, 1, m) {
            prefix[i] = prefix[i-1] + prices[i-1];
        }
        // showArr("prefix:", prefix, m+1);


        // 1-index graph
        vector<point> graph(n+1);
        FOR(i, 0, n) 
        {
            graph[i].index = i;
        }

        REP(i, m) {
            get(u);get(v);
            graph[u].adj.eb(v);
            graph[v].adj.eb(u);
        }

        queue<point> bfsQueue;

        graph[a].aDist = 0;
        bfsQueue.push(graph[a]);
        while (!bfsQueue.empty()) {
            point p = bfsQueue.front();
            bfsQueue.pop();

            for (auto& adjIndex : p.adj) {
                point& adjPoint = graph[adjIndex];
                if (adjPoint.aDist > p.aDist + 1) {
                    adjPoint.aDist = p.aDist + 1;
                    bfsQueue.push(adjPoint);
                }
            }
        }

        graph[c].cDist = 0;
        bfsQueue.push(graph[c]);
        while (!bfsQueue.empty()) {
            point p = bfsQueue.front();
            bfsQueue.pop();

            for (auto& adjIndex : p.adj) {
                point& adjPoint = graph[adjIndex];
                if (adjPoint.cDist > p.cDist + 1) {
                    adjPoint.cDist = p.cDist + 1;
                    bfsQueue.push(adjPoint);
                }
            }
        }

        ll ans = 0x7f7f7f7f7f7f7f7f;
        graph[b].bDist = 0;
        bfsQueue.push(graph[b]);
        while (!bfsQueue.empty()) {
            point p = bfsQueue.front();
            bfsQueue.pop();
            if (p.bDist > graph[b].aDist + graph[b].cDist)
                break;

            // show("totalDist = ", p.bDist + p.aDist + p.cDist);
            // show("aDist = ", p.aDist);
            // show("bDist = ", p.bDist);
            // show("cDist = ", p.cDist);
            if (p.bDist + p.aDist + p.cDist <= m) {
                ans = min(ans, prefix[p.bDist] + prefix[p.bDist + p.aDist + p.cDist]);
            }

            for (auto& adjIndex : p.adj) {
                point& adjPoint = graph[adjIndex];
                if (adjPoint.bDist > p.bDist + 1) {
                    adjPoint.bDist = p.bDist + 1;
                    bfsQueue.push(adjPoint);
                }
            }
        }

        // cout << "aDist:" << endl;
        // FOR(i, 1, n) {
        //     cout << graph[i].aDist << " ";
        // }
        // ln;
        // cout << "cDist:" << endl;
        // FOR(i, 1, n) {
        //     cout << graph[i].cDist << " ";
        // }
        // ln;

        cout << ans << endl;
    }
}