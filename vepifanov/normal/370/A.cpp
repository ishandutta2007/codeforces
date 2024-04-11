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
int x1, y1, x2, y2;

int main () {
    scanf ("%d%d%d%d", &x1, &y1, &x2, &y2);
    int a1 = 0, a2 = 0, a3 = max (abs (x2 - x1), abs (y2 - y1));
    if (x1 != x2) a1++;
    if (y1 != y2) a1++;
    if ((x1 + y1) % 2 == (x2 + y2) % 2) {
        if (x1 + y1 == x2 + y2 || x1 - y1 == x2 - y2) a2 = 1; else a2 = 2;
    }
    printf ("%d %d %d\n", a1, a2, a3);
    return 0;
}