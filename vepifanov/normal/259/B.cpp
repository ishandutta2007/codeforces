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

int n;
int m;
int g[3][3];

int main () {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            scanf ("%d", &g[i][j]);
    for (int a = 1; a <= 100000; a++) {
        int b = g[0][1] + g[0][2] + a - g[1][0] - g[1][2];
        int c = g[0][1] + g[0][2] + a - g[2][0] - g[2][1];
        if (b >= 1 && b <= 100000 && c >= 1 && c <= 100000 && a + c == g[0][2] + g[2][0]) {
            g[0][0] = a;
            g[1][1] = b;
            g[2][2] = c;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++)
                    printf ("%d ", g[i][j]);
                printf ("\n");
            }
            re 0;
        }
    }
    return 0;
}