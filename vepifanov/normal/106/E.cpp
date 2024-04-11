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
int x[100], y[100], z[100];

int main () {
    scanf ("%d", &n);   
    double X = 0, Y = 0, Z = 0;
    for (int i = 0; i < n; i++) {
        scanf ("%d%d%d", &x[i], &y[i], &z[i]);
        X += x[i];
        Y += y[i];
        Z += z[i];
    }   
    X /= n; Y /= n; Z /= n;
    double len = 1;
    for (int it = 0; it < 50000; it++) {
        double cur = 0;
        int j = 0;
        for (int i = 0; i < n; i++) {
            double tmp = sqrt (sqr (X - x[i]) + sqr (Y - y[i]) + sqr (Z - z[i]));
            if (tmp > cur) {
                cur = tmp;
                j = i;
            }
        }
        X += len * (x[j] - X);
        Y += len * (y[j] - Y);
        Z += len * (z[j] - Z);
        len *= 0.999;
    }
    printf ("%.10f %.10f %.10f\n", X, Y, Z);
    return 0;
}