#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <deque>
#include <cassert>
#include <iomanip>      
#define pb push_back
#define x first
#define y second
#define files(FILENAME) read(FILENAME); write(FILENAME)
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
using namespace std;
  
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }


const string FILENAME = "input";
typedef pair<int, int> point;
typedef long double base;

const int MAXN = 2e5 + 1;

int n;
int dist[MAXN][3];
vector<int> edge[MAXN];

void bfs(int s, int p) {
    for (int i = 0; i < n; ++i) {
        dist[i][p] = 1e9;
    }
    dist[s][p] = 0;
    queue<int> que;
    que.push(s);
    while (que.size()) {
        int v = que.front();
        que.pop();
        for (auto u : edge[v]) {
            if (dist[u][p] == 1e9) {
                dist[u][p] = dist[v][p] + 1;
                que.push(u);
            }
        }
    }
}

int d;
int rep[MAXN];

bool cmp(int i, int j) {
    return dist[i][0] > dist[j][0];
}

long long ans;
vector<int> res;
vector<pair<pair<int, int>, int>> repr;

int main() {
	srand(time(0));
    //read(FILENAME);
	ios::sync_with_stdio(0);
	cin >> n;
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        edge[a].pb(b);
        edge[b].pb(a);
    }
    bfs(0, 2);
    int L = 0, R = 0;
    for (int i = 0; i < n; ++i) {
        if (dist[L][2] < dist[i][2]) {
            L = i;
        }
    }
    bfs(L, 0);
    for (int i = 0; i < n; ++i) {
        if (dist[R][0] < dist[i][0]) {
            R = i;
        }
    }
    bfs(R, 1);
    d = dist[R][0];
    for (int i = 0; i < n; ++i) {
        if (dist[i][0] + dist[i][1] != d) {
            res.pb(i);
        } else {
            rep[dist[i][0]] = i;
        }
    }
    sort(res.begin(), res.end(), cmp);
    for (int i : res) {
        if (dist[i][0] > dist[i][1]){
            ans += dist[i][0];
            repr.pb({{i, L}, i});
        } else {
            ans += dist[i][1];
            repr.pb({{i, R}, i});
        }
    }
    for (int i = 0; i < d; ++i) {
        ans += d - i;
        repr.pb({{rep[i], R}, rep[i]});
    }
    cout << ans << endl;
    for (auto i : repr) {
        cout << i.x.x + 1 << ' ' << i.x.y + 1 << ' ' << i.y + 1 << '\n';
    }
}