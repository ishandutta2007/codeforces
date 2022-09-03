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
int was[1001][1001][2];
double res[1001][1001][2];

double go (int n, int m, int k) {   
    if (n == 0 && m == 0) re int (k == 1);
    if (was[n][m][k]) re res[n][m][k];
    was[n][m][k] = 1;
    double cur = 0;
    if (k == 1) {
        if (n > 0) cur += (n + 0.0) / (n + m);
        if (m > 0) {
            if (n > 0) cur += (m + 0.0) / (n + m) * (n + 0.0) / (n + m - 1) * (1 - go (n - 1, m - 1, 0));
            if (m > 1) cur += (m + 0.0) / (n + m) * (m - 1.0) / (n + m - 1) * (1 - go (n, m - 2, 0));
            if (n == 0 && m == 1) cur = 1;
        }
    } else {
        if (n > 0) cur += (n + 0.0) / (n + m);
        if (m > 0) cur += (m + 0.0) / (n + m) * (1 - go (n, m - 1, 1));
    }
    re res[n][m][k] = cur;
}

int main () {
    scanf ("%d%d", &n, &m);
    printf ("%.10f\n", go (n, m, 0));
    return 0;
}