#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <queue>
#include <sstream>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < n; i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define y0 y3487465
#define y1 y8687969

typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) {
    re x > 0 ? x : -x;
}

int n;
int m;
int g[100][100], x[2001], cnt[100], was[100], y[2001];

int dfs (int x) {
    was[x] = 1;
    for (int i = 0; i < n; i++)
        if (g[x][i] && !was[i])
            dfs (i);
    re 0;
}

int check (int i) {
    for (int j = 0; j < n; j++)
        if (j != y[i] && j != y[0] && (cnt[j] & 1))
            re 0;
    if (y[0] == y[i] && (cnt[y[0]] & 1) || y[0] != y[i] && ((cnt[y[0]] & 1) == 0 || (cnt[y[i]] & 1) == 0)) re 0;
    memset (was, 0, sizeof (was));
    for (int j = 0; j < n; j++)
        if (cnt[j]) {
            dfs (j);
            break;
        }
    for (int j = 0; j < n; j++)
        if (!was[j] && cnt[j])
            re 0;
    re 1;
}

int go (int i, int f) {
    if (i == m) {
        y[i] = y[0];
        re (1 - f) * int (g[y[i - 1]][y[i]]);
    }
    y[i] = x[i] * f;
    while (y[i] < n) {
        if (i > 0) {
            if (!g[y[i]][y[i - 1]]) { y[i]++; continue; }
            g[y[i]][y[i - 1]] = g[y[i - 1]][y[i]] = 0;
            cnt[y[i]]--; cnt[y[i - 1]]--;
        }
        if (check (i) && go (i + 1, min (f, 1 - int (y[i] > x[i])))) re 1;
        if (i > 0) {
            g[y[i]][y[i - 1]] = g[y[i - 1]][y[i]] = 1;
            cnt[y[i]]++; cnt[y[i - 1]]++;
        }
        y[i]++;
    }
    re 0;
}

int main() {
    scanf ("%d%d", &n, &m); 
    for (int i = 0; i <= m; i++) {
        scanf ("%d", &x[i]);
        x[i]--;
    }
    for (int i = 0; i < m; i++) {
        cnt[x[i]]++;
        cnt[x[i + 1]]++;
        g[x[i]][x[i + 1]] = g[x[i + 1]][x[i]] = 1;
    }   
    y[0] = x[0];
    if (go (1, 1)) {
        for (int i = 0; i <= m; i++) printf ("%d ", y[i] + 1);
        printf ("\n");
    } else printf ("No solution\n");
    return 0;
}