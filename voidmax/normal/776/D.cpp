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
#define For(i, a, b) for (int i = a; i < b; ++i)
#define Out(i, a, b) for (int i = a - 1; i >= b; --i)
#define pb push_back
#define point pair <int, int>
#define x first
#define y second
#define files(FileName) read(FileName); write(FileName)
#define read(FileName) freopen((FileName + ".in").c_str(), "r", stdin)
#define write(FileName) freopen((FileName + ".out").c_str(), "w", stdout)
using namespace std;
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }

const string FILENAME = "input";

const int MAXN = 1e5;

int n, m;
vector <int> edge[200001];
vector <int> on[100001];
bool open[100001], used[200001];
int cnt = 1, color[200001];

vector <int> top;

void dfs(int i) {
    if (used[i]) return;
    used[i] = true;
    for (int j: edge[i]) {
        dfs(j);
    }
    top.pb(i);
}

void dfs_color(int i) {
    if (color[i]) return;
    color[i] = cnt;
    for (int j: edge[i]) {
        dfs_color(j);
    }
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(0);
    srand(time(0));
    //read(FILENAME);
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> open[i];
    for (int i = 0; i < m; ++i) {
        int len;
        cin >> len;
        for (int j = 0; j < len; ++j) {
            int a;
            cin >> a;
            --a;
            on[a].pb(i);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (!open[i]) {
            edge[on[i][0] + MAXN].pb(on[i][1]);
            edge[on[i][1]].pb(on[i][0] + MAXN);
            edge[on[i][1] + MAXN].pb(on[i][0]);
            edge[on[i][0]].pb(on[i][1] + MAXN);
        } else {
            edge[on[i][0] + MAXN].pb(on[i][1] + MAXN);
            edge[on[i][1]].pb(on[i][0]);
            edge[on[i][1] + MAXN].pb(on[i][0] + MAXN);
            edge[on[i][0]].pb(on[i][1]);
        }
    }
    for (int i = 0; i < m; ++i) {
        dfs(i), dfs(i + MAXN);
    }
    for (int i: top) {
        dfs_color(i);
        ++cnt;
    }
    for (int i = 0; i < m; ++i) {
        if (color[i] == color[i + MAXN]) {
            cout << "NO" << endl;
            exit(0);
        }
    }
    cout << "YES" << endl;
}