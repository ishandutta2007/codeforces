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
ii v[100000];
int a[100000];
int b[100000];

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf ("%d", &v[i].fi);
        v[i].se = i;
    }
    sort (v, v + n);
    for (int i = 0; i < n; i++)
        if (i < n / 3) {
            a[v[i].se] = i;
            b[v[i].se] = v[i].fi - i;
        } else
        if (i < 2 * n / 3) {
            b[v[i].se] = i;
            a[v[i].se] = v[i].fi - i;
        } else {
            b[v[i].se] = n - i - 1;
            a[v[i].se] = v[i].fi - (n - i - 1);
        }
    printf ("YES\n");
    for (int i = 0; i < n; i++) printf ("%d ", a[i]);
    printf ("\n");
    for (int i = 0; i < n; i++) printf ("%d ", b[i]);
    printf ("\n");
    return 0;
}