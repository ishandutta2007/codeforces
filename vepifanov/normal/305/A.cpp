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
int y[100];
int z[100];

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf ("%d", &x);
        z[i] = x;
        y[i] = 0;
        int base = 1;
        while (x) {
            y[i] += base * int (x % 10 != 0);
            x /= 10;
            base *= 2;
        }
    }
    int ans = 1, a = 0, b, c, d;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if ((y[i] & y[j]) == 0) {
                if (ans < 2) {
                    ans = 2;
                    a = i;
                    b = j;
                }
                for (int k = j + 1; k < n; k++)
                    if ((y[i] & y[k]) == 0 && (y[j] & y[k]) == 0) {
                        if (ans < 3) {
                            ans = 3;
                            a = i;
                            b = j;
                            c = k;
                        }
                        for (int t = k + 1; t < n; t++)
                            if ((y[i] & y[t]) == 0 && (y[j] & y[t]) == 0 && (y[k] & y[t]) == 0) {
                                ans = 4;
                                a = i;
                                b = j;
                                c = k;
                                d = t;
                            }
                    }
            }
    printf ("%d\n", ans);  
    if (ans >= 1) printf ("%d ", z[a]);
    if (ans >= 2) printf ("%d ", z[b]);
    if (ans >= 3) printf ("%d ", z[c]);
    if (ans >= 4) printf ("%d ", z[d]);
    printf ("\n");
    return 0;
}