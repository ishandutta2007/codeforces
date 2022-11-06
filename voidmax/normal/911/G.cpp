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

const int MAXN = 1 << 18;

int n, m;
int a[MAXN];
char c[MAXN * 2][100];

void push(int i) {
    if (i < MAXN) {
        for (int j = 0; j < 100; ++j) {
            c[i * 2][j] = c[i][c[i * 2][j]];
            c[i * 2 + 1][j] = c[i][c[i * 2 + 1][j]];
        }
        for (int j = 0; j < 100; ++j) {
            c[i][j] = j;
        }
    }
}


int Ln, Rn, X, Y;

void change(int i, int L, int R) {
    if (R <= Ln || Rn <= L) return;
    if (Ln <= L && R <= Rn) {
        for (int j = 0; j < 100; ++j) {
            if (c[i][j] == X) {
                c[i][j] = Y;
            }
        }
        return;
    }
    push(i);
    int M = (L + R) >> 1;
    change(i * 2, L, M);
    change(i * 2 + 1, M, R);
}

int main() {
	srand(time(0));
	ios::sync_with_stdio(0);
	//read(FILENAME);
	cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
    }
    for (int i = 0; i < MAXN * 2; ++i) {
        for (int j = 0; j < 100; ++j) {
            c[i][j] = j;
        }
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> Ln >> Rn >> X >> Y;
        --Ln, --X, --Y;
        change(1, 0, MAXN);
    }
    for (int i = 1; i < MAXN * 2; ++i) push(i);
    for (int i = 0; i < n; ++i) {
        cout << int(c[i + MAXN][a[i]]) + 1 << ' ';
    }
    cout << '\n';
}