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
vs res;
int x[12];

int gen (int n) {
    if (n < 4) re 0;
    for (int a = 1; a <= 3 && a <= n; a++)
        for (int b = 1; b <= 3 && a + b <= n; b++)
            for (int c = 1; c <= 3 && a + b + c <= n; c++) {
                int d = n - a - b - c;
                if (d >= 1 && d <= 3) {
                    if (x[0] == 0 && a > 1) continue;
                    if (x[a] == 0 && b > 1) continue;
                    if (x[a + b] == 0 && c > 1) continue;
                    if (x[a + b + c] == 0 && d > 1) continue;
                    int tmp, t1, t2, t3, t4;
                    tmp = 0;
                    for (int i = 0; i < a; i++) tmp = tmp * 10 + x[i];
                    if (tmp > 255) continue;
                    t1 = tmp;
                    tmp = 0;
                    for (int i = 0; i < b; i++) tmp = tmp * 10 + x[a + i];
                    if (tmp > 255) continue;
                    t2 = tmp;
                    tmp = 0;
                    for (int i = 0; i < c; i++) tmp = tmp * 10 + x[a + b + i];
                    if (tmp > 255) continue;
                    t3 = tmp;
                    tmp = 0;
                    for (int i = 0; i < d; i++) tmp = tmp * 10 + x[a + b + c + i];
                    if (tmp > 255) continue;
                    t4 = tmp;
                    char h[20];
                    h[0] = 0;
                    sprintf (h, "%d.%d.%d.%d", t1, t2, t3, t4);
                    res.pb (string (h));
                }
            }
    re 0;
}

int go (int n, int now, int can) {
    if (n > 0 && now == can) {
        for (int i = 0; i < n; i++) x[n + i] = x[n - i - 1];
        gen (2 * n);
        for (int i = 0; i < n; i++) x[n + i - 1] = x[n - i - 1];
        gen (2 * n - 1);
    }
    if (n < 6)
        for (int t = 0; t < 10; t++)
            if ((can >> t) & 1) {
                x[n] = t;
                go (n + 1, now | (1 << t), can);
            }   
    re 0;
}

int main () {
    scanf ("%d", &n);
    int can = 0;
    for (int i = 0; i < n; i++) {
        int x;
        scanf ("%d", &x);
        can |= 1 << x;
    }
    go (0, 0, can);
    printf ("%d\n", sz (res));
    for (int i = 0; i < sz (res); i++) printf ("%s\n", res[i].c_str ());
    return 0;
}