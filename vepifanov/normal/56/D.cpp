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
string a, b;
int was[1001][1001];
int res[1001][1001];
int prev[1001][1001];

int go (int i, int j) {
    if (i == n && j == m) re 0;
    if (was[i][j]) re res[i][j];
    was[i][j] = 1;
    res[i][j] = 1e9;
    if (i < n && j < m && res[i][j] > go (i + 1, j + 1) + int (a[i] != b[j])) {
        res[i][j] = go (i + 1, j + 1) + int (a[i] != b[j]);
        prev[i][j] = 0;
    }
    if (i < n && res[i][j] > go (i + 1, j) + 1) {
        res[i][j] = go (i + 1, j) + 1;
        prev[i][j] = 1;
    }
    if (j < m && res[i][j] > go (i, j + 1) + 1) {
        res[i][j] = go (i, j + 1) + 1;
        prev[i][j] = 2;
    }
    re res[i][j];
}

int out (int i, int j) {
    if (i == n && j == m) re 0;
    if (prev[i][j] == 0) {
        out (i + 1, j + 1); 
        if (a[i] != b[j]) printf ("REPLACE %d %c\n", i + 1, b[j]);
    } else
    if (prev[i][j] == 1) {
        out (i + 1, j);
        printf ("DELETE %d\n", i + 1);
    } else {
        out (i, j + 1);
        printf ("INSERT %d %c\n", i + 1, b[j]);
    }
    re 0;
}

int main() {
    cin >> a >> b;
    n = sz (a); m = sz (b);
    printf ("%d\n", go (0, 0));
    out (0, 0);
    return 0;
}