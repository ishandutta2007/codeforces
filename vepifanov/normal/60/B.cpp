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
int K;
string g[11][11];
int qi[10000], qj[10000], qk[10000];
                                  
int main() {
    cin >> K >> n >> m;
    for (int i = 0; i < K; i++)
        for (int j = 0; j < n; j++)
            cin >> g[i][j];

    int x, y;
    cin >> x >> y; x--; y--;

    int l = 0, r = 1;
    qi[0] = 0;
    qj[0] = x;
    qk[0] = y;
    g[0][x][y] = '#';
    while (l < r) {
        int i = qi[l];
        int j = qj[l];
        int k = qk[l];
        l++;
        for (int d = 0; d < 6; d++) {
            int ni = i + int (d == 0) - int (d == 1);
            int nj = j + int (d == 2) - int (d == 3);
            int nk = k + int (d == 4) - int (d == 5);
            if (ni >= 0 && nj >= 0 && nk >= 0 && ni < K && nj < n && nk < m && g[ni][nj][nk] == '.') {
                g[ni][nj][nk] = '#';
                qi[r] = ni;
                qj[r] = nj;
                qk[r] = nk;
                r++;
            }
        }
    }
    printf ("%d\n", r);
    return 0;
}