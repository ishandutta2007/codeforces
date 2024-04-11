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

int main () {
    scanf ("%d%d", &n, &m); 
    for (int i = 0; i < n; i++) {
        int s, f, t, x;
        scanf ("%d%d%d", &s, &f, &t); s--; f--;
        if (s == f) { printf ("%d\n", t); continue; }
        if (t % (2 * m - 2) < m) {
            x = t % (2 * m - 2);
            if (x <= s) {
                if (s <= f) t += f - x; else t += (m - x - 1) + (m - f - 1);
            } else {
                if (s <= f) t += (m - x - 1) + m - 1 + f; else t += (m - x - 1) + (m - f - 1);
            }
        } else {
            x = 2 * m - 2 - t % (2 * m - 2);
            if (x >= s) {
                if (s >= f) t += x - f; else t += x + f;
            } else {
                if (s >= f) t += x + m - 1 + (m - f - 1); else t += f + x;
            }
        }
        printf ("%d\n", t);
    }
    return 0;
}