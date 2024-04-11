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
    int p = int (n < 0);
    int q = int (m < 0);
    n = abs (n);
    m = abs (m);
    int x1 = 0, y1 = q ? -(n + m) : n + m;
    int x2 = p ? -(n + m) : n + m, y2 = 0;
    if (x1 > x2) {
        swap (x1, x2);
        swap (y1, y2);
    }
    printf ("%d %d %d %d\n", x1, y1, x2, y2);
    return 0;
}