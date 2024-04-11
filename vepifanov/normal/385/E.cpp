#include <cstdio>
#include <numeric>
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
#include <deque>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define fill(x,y) memset(x,y,sizeof(x))
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

const int g[6][6] = {{2, 1, 1, 1, 0, 0},
             {1, 2, 1, 1, 0, 0},
             {1, 0, 1, 0, 0, 0},
             {0, 1, 0, 1, 0, 0},
             {1, 1, 1, 1, 1, 0},
             {0, 0, 0, 0, 1, 1}};

int n;
int m;
ll t;
int sx, sy, dx, dy;
int e[6][6];
int w[6][6];
int h[6][6];
int a[6];
int b[6];

int main () {
    cin >> n >> sx >> sy >> dx >> dy >> t;
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 6; j++) {
            e[i][j] = int (i == j);
            w[i][j] = g[i][j];
        }   
    while (t) {
        if (t & 1) {
            for (int i = 0; i < 6; i++)
                for (int j = 0; j < 6; j++) {
                    int tmp = 0;
                    for (int k = 0; k < 6; k++)
                        tmp = (tmp + (ll)e[i][k] * w[k][j]) % n;
                    h[i][j] = tmp;
                }
            for (int i = 0; i < 6; i++)
                for (int j = 0; j < 6; j++)
                    e[i][j] = h[i][j];
        }
        for (int i = 0; i < 6; i++)
            for (int j = 0; j < 6; j++) {
                int tmp = 0;
                for (int k = 0; k < 6; k++)
                    tmp = (tmp + (ll)w[i][k] * w[k][j]) % n;
                h[i][j] = tmp;
            }
        for (int i = 0; i < 6; i++)
            for (int j = 0; j < 6; j++)
                w[i][j] = h[i][j];
        t /= 2;
    }
    a[0] = sx; a[1] = sy; a[2] = dx; a[3] = dy; a[4] = 0; a[5] = 1;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++)
            b[i] = (b[i] + (ll)a[j] * e[j][i]) % n;
        if (b[i] < 0) b[i] += n;
        if (i < 2 && b[i] == 0) b[i] = n;
    }
/*  for (int i = 0; i < 2; i++) printf ("%d ", b[i]);
    printf ("\n");*/
    printf ("%d %d\n", b[0], b[1]);
    return 0;
}