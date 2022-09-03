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
int m, k;
double x[100];
int was[100];

int main () {
    scanf ("%d%d", &n, &m); 
    int l = n / m;
    for (int i = 0; i < n; i++) scanf ("%lf", &x[i]);
    scanf ("%d", &k);
    double a1 = 1e9, a2 = -1e9;
    for (int i = 0; i < k; i++) {
        double sum = 0;
        for (int j = 0; j < l; j++) {
            int a;
            scanf ("%d", &a); a--;
            was[a] = 1;
            sum += x[a];
        }
        a1 = min (a1, sum);
        a2 = max (a2, sum);
    }
    vector<D> v;
    for (int i = 0; i < n; i++)
        if (!was[i])
            v.pb (x[i]);
    sort (all (v));
    if (sz (v) >= l && n - sz (v) < m * l) {
        double sum = 0;
        for (int i = 0; i < l; i++) sum += v[i];
        a1 = min (a1, sum);
        sum = 0;
        for (int i = 0; i < l; i++) sum += v[sz (v) - i - 1];
        a2 = max (a2, sum);
    }   
    printf ("%.10f %.10f\n", a1 / l, a2 / l);
    return 0;
}