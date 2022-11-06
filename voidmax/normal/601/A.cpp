#include <iostream>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
#include <cstdio>
#define x first
#define y second
#define point pair <double, double>
#define For(i, a, b) for(int i = a; i < b; ++i)
#define Out(i, a, b) for(int i = a - 1; i >= b; --i)
using namespace std;


///i will find you!!!

typedef long long ll;

int n, m;
bool OK = false;
vector <int> arr[401][2];
int used[401];
bool UsedE[401][401];

int dfs() {
    queue <int> que;
    For(i, 0, n) used[i] = 1e9;
    used[0] = 0;
    que.push(0);
    while (que.size() != 0) {
        int u = que.front(); que.pop();
        for(int v: arr[u][OK]) {
            if (used[v] > used[u] + 1) {
                used[v] = used[u] + 1;
                que.push(v);
            }
        }
    }
    if (used[n - 1] == 1e9) return -1;
    return used[n - 1];
 }

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    For(i, 0, m) {
        int L, R; cin >> L >> R;
        if ((L == 1 && R == n) || (L == n && R == 1)) OK = true;
        --L; --R;
        arr[L][0].push_back(R);
        arr[R][0].push_back(L);
        UsedE[L][R] = true;
        UsedE[R][L] = true;
    }
    For(i, 0, n) {
        For(j, 0, n) {
            if (!UsedE[i][j]) {
                arr[i][1].push_back(j);
            }
        }
    }
    cout << dfs();
}