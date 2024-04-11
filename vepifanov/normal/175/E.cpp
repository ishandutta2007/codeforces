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

const int mn = 10;

int n;
int m;
int n1, n2, n3;
double r1, r2, r3, d1, d2;
int was[mn][21][21];
double res[mn][21][21];
double pd1[mn], pd2[mn];
int q[mn];
int s[mn];
int ct;

double get (double x, double r) {
    double tmp = 2 * r;
    for (int i = 0; i < mn; i++) {
        double L = max (i - r3, x - r);
        double R = min (i + r3, x + r);
        tmp += q[i] * max (R - L, 0.0);
    }
    re tmp;
}

double go2 (int i, int j, int k) {
    if (i == mn || j == 0 && k == 0) re 0;
    if (s[i] < j + k) re 0;
    if (was[i][j][k] == ct) re res[i][j][k];
    was[i][j][k] = ct;
    double cur = go2 (i + 1, j, k);
    if (q[i] < 2) {
        q[i]++;
        s[i]--;
        if (j) cur = max (cur, go2 (i, j - 1, k) + pd1[i]);
        if (k) cur = max (cur, go2 (i, j, k - 1) + pd2[i]);
        q[i]--;
        s[i]++;
    }
    re res[i][j][k] = cur;
}

double calc () {
    for (int i = 0; i < mn; i++) {
        pd1[i] = get (i, r1) * d1;
        pd2[i] = get (i, r2) * d2;
//      printf ("%.10f %.10f\n", pd1[i], pd2[i]);
    }
    for (int i = mn - 1; i >= 0; i--) {
        s[i] = 2 - q[i];
        if (i + 1 < mn) s[i] += s[i + 1];
    }
    ct++;
    re go2 (0, n1, n2);
}

double go (int i, int j) {
    if (i == mn || j == 0) re calc ();
    if ((mn - i) * 2 < j) re 0;
    q[i] = 0;
    double cur = go (i + 1, j);
    if (j > 0) {
        q[i] = 1;
        cur = max (cur, go (i + 1, j - 1));
    }
    if (j > 1) {
        q[i] = 2;
        cur = max (cur, go (i + 1, j - 2));
    }
    q[i] = 0;
    re cur;

}

int main () {
    cin >> n1 >> n2 >> n3;
    cin >> r1 >> r2 >> r3;
    r1 = sqrt (r1 * r1 - 1);
    r2 = sqrt (r2 * r2 - 1);
    r3 = sqrt (r3 * r3 - 1);
    cin >> d1 >> d2;
    printf ("%.10f\n", go (0, n3));
    return 0;
}