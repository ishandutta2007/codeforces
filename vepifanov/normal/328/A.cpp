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

int x[4];

int main () {
    for (int i = 0; i < 4; i++) scanf ("%d", &x[i]);
    if (x[1] - x[0] == x[2] - x[1] && x[2] - x[1] == x[3] - x[2]) printf ("%d\n", x[3] + (x[3] - x[2])); else
    if (x[0] != 0 && x[1] != 0 && x[2] != 0 && x[3] != 0 && sqr (x[1]) == x[0] * x[2] && sqr (x[2]) == x[1] * x[3] && sqr (x[3]) % x[2] == 0) printf ("%d\n", x[3] * x[3] / x[2]); else printf ("42\n");
    return 0;
}