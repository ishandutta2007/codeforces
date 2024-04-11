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
int x[300];
int y[300];

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) scanf ("%d%d", &x[i], &y[i]);
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            int a1 = -1e9, a2 = 1e9;
            int b1 = -1e9, b2 = 1e9;
            for (int k = 0; k < n; k++)
                if (k != i && k != j) {
                    int v = (x[k] - x[i]) * (y[j] - y[i]) - (x[j] - x[i]) * (y[k] - y[i]);
                    if (v >= 0) {
                        a1 = max (a1, v);
                        a2 = min (a2, v);
                    }
                    if (v <= 0) {
                        b1 = max (b1, -v);
                        b2 = min (b2, -v);
                    }
                }
            ans = max (ans, a1 + b1);
            ans = max (ans, a1 - a2);
            ans = max (ans, b1 - b2);
        }
    printf ("%.10f\n", ans / 2.0);
    return 0;
}