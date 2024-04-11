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
char g[4][101];

int main() {
    scanf ("%d", &n);
    if (n == 1) {
        g[0][0] = g[1][0] = 'a';
        g[2][0] = g[3][0] = 'b';
    } else {
        int k = 0, q = 0;
        g[0][0] = g[1][0] = 'a';
        for (int i = 0; i + 1 < n; i++) {
            q ^= 1;
            k = (k + 1) % 26;
            g[q * 2][i] = g[q * 2][i + 1] = 'a' + k;
            k = (k + 1) % 26;
            g[q * 2 + 1][i] = g[q * 2 + 1][i + 1] = 'a' + k;
        }
        q ^= 1;
        k = (k + 1) % 26;
        g[q * 2][n - 1] = g[q * 2 + 1][n - 1] = 'a' + k;
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < n; j++)
            printf ("%c", g[i][j]);
        printf ("\n");
    }
    return 0;
}