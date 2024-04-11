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
#include <cassert>

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
#define prev PREV
#define j0 j1347829
#define j1 j234892
#define next NEXT
                         
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
int d, x;
int a[100010];
int b[100010];
int p[100010];
int c[100010];
int q[100010];
int next[100010];

int myrand () {
    x = ((ll)x * 37 + 10007) % 1000000007;
    re x;
}

int gp (int x) {
    if (x == n || c[x] == -1) re x;
    re next[x] = gp (next[x]);
}

int main () {
    scanf ("%d%d%d", &n, &d, &x);
    for (int i = 0; i < n; i++) a[i] = i;
    for (int i = 0; i < n; i++) swap (a[i], a[myrand () % (i + 1)]);
    for (int i = 0; i < n; i++) b[i] = int (i < d);
    for (int i = 0; i < n; i++) swap (b[i], b[myrand () % (i + 1)]);
//    for (int i = 0; i < n; i++) printf ("%d ", a[i]);
//    printf ("\n");
//    for (int i = 0; i < n; i++) printf ("%d ", b[i]);
//    printf ("\n");
    if (d <= n / d) {
        for (int i = 0, j = 0; i < n; i++)
            if (b[i])
                p[j++] = i;
        for (int i = 0; i < n; i++) {
            c[i] = -1;
            q[a[i]] = i;
        }   
        for (int i = n - 1; i >= 0; i--) {
            int k = q[i];
            for (int j = 0; j < d && k + p[j] < n; j++)
                if (c[k + p[j]] == -1)
                    c[k + p[j]] = i;
        }
    } else {
        for (int i = 0; i < n; i++) {
            next[i] = i + 1;
            c[i] = -1;
            q[a[i]] = i;
        }
        for (int i = n - 1; i >= 0; i--) {
            int k = q[i], f = q[i];
            while (k < n) {
                k = gp (k);
                if (k == n) break;
//              printf ("%d %d %d\n", i, f, k);
                if (b[k - f]) c[k] = i;
                k = next[k];
            }
        }
    }
    for (int i = 0; i < n; i++) printf ("%d\n", c[i] + 1);
//    cerr << clock () << endl;
    return 0;
}