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
int was[500][500][2][2];
int res[500][500][2][2];
int x, y, dx[20], dy[20], d;

int go (int x, int y, int a, int b) {
    if (x * x + y * y > d * d) re 1;
    if (was[x + 200][y + 200][a][b]) re res[x + 200][y + 200][a][b];
    was[x + 200][y + 200][a][b] = 1;
    res[x + 200][y + 200][a][b] = 0;
    if (!a && !go (y, x, b, 1)) res[x + 200][y + 200][a][b] = 1;
    for (int i = 0; i < n; i++)
        if (!go (x + dx[i], y + dy[i], b, a)) {
            res[x + 200][y + 200][a][b] = 1;
            break;
        }
    re res[x + 200][y + 200][a][b];
}

int main() {
    scanf ("%d%d%d%d", &x, &y, &n, &d);
    for (int i = 0; i < n; i++) scanf ("%d%d", &dx[i], &dy[i]);
    if (go (x, y, 0, 0)) printf ("Anton\n"); else printf ("Dasha\n");
    return 0;
}