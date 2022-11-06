#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <bitset>
#include <map>
#include <set>
#include <vector>
#include <string>
#define x first
#define y second
#define For(i, a, b) for(int i = a; i < b; ++i)
#define Out(i, a, b) for(int i = a - 1; i >= b; --i)
#define point pair<int, int>

using namespace std;

typedef long long base;

int n, m;
bool arr[501][501];
bool color[501][501];
int used[501];
int cnt = 1;
set <int> have[32];
char need[32];

void dfs(int i) {
    if (used[i]) return;
    used[i] = cnt;
    For(j, 0, n) if (color[i][j]) dfs(j);
}

int main() {
    //freopen("trains.in", "r", stdin);
    //freopen("trains.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    For(i, 0, m) {
        int L, R; cin >> L >> R; --L; --R;
        arr[L][R] = arr[R][L] = 1;
    }
    For(i, 0, n) arr[i][i] = 1;
    For(i, 0, n) {
        For(j, i + 1, n) {
            bool OK = true;
            For(k, 0, n) {
                if (arr[i][k] != arr[j][k]) {
                    OK = false;
                    break;
                }
            }
            color[i][j] = color[j][i] = OK;
        }
    }
    For(i, 0, n) {
        if (!used[i]) {
            dfs(i);
            ++cnt;
        }
    }
    if (cnt > 30) {
        cout << "No";
        return 0;
    }
    For(i, 0, n) {
        For(j, i + 1, n) {
            if (arr[i][j] && used[i] != used[j]) {
                have[used[i]].insert(used[j]);
                have[used[j]].insert(used[i]);
            }
        }
    }
    For(i, 1, 27) {
        if (have[i].size() >= 3) {
            cout << "No";
            return 0;
        }
    }
    char ML = 'a';
    For(i, 1, cnt) {
        if (need[i] == 0) {
            if (have[i].size() < 2) {
                int j = i;
                while (have[j].size() != 0) {
                    int Next = *have[j].begin();
                    need[j] = ML; ++ML;
                    have[j].erase(Next);
                    have[Next].erase(j);
                    j = Next;
                }
                need[j] = ML;
                ML += 2;
            }
        }
    }
    For(i, 0, n) {
        if (need[used[i]] > 'c' || need[used[i]] == 0) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes\n";
    For(i, 0, n) {
        cout << need[used[i]];
    }
}