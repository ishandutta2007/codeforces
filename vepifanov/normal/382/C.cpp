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
int x[100000];

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
    sort (x, x + n);
    if (n == 1) {
        printf ("-1\n");
        re 0;
    }   
    if (x[0] == x[n - 1]) {
        printf ("1\n%d\n", x[0]);
        re 0;
    }
    if (n == 2) {
        if ((x[1] - x[0]) % 2 == 0) 
            printf ("3\n%d %d %d\n", x[0] - (x[1] - x[0]), (x[0] + x[1]) / 2, x[1] + (x[1] - x[0]));
        else 
            printf ("2\n%d %d\n", x[0] - (x[1] - x[0]), x[1] + (x[1] - x[0]));
        re 0;
    }
    int ok = 1;
    for (int i = 0; i + 2 < n; i++)
        if (x[i + 1] - x[i] != x[i + 2] - x[i + 1])
            ok = 0;
    if (ok) {
        if (x[0] == x[n - 1]) printf ("1\n%d\n", x[0]); else printf ("2\n%d %d\n", x[0] - (x[1] - x[0]), x[n - 1] + (x[1] - x[0]));
    } else {
        if ((x[n - 1] - x[0]) % n == 0) {
            int d = (x[n - 1] - x[0]) / n;
            int cur = 0, pos = 0;
            for (int i = 0; i + 1 < n; i++)
                if (x[i + 1] - x[i] != d) {
                    if (x[i + 1] - x[i] == 2 * d) {
                        cur++;
                        pos = x[i] + d;
                    } else {
                        cur = 0;
                        break;
                    }
                }   
            if (cur != 1) printf ("0\n"); else printf ("1\n%d\n", pos);
        } else printf ("0\n");
    }
    return 0;
}