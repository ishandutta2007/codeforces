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

#define filename ""

int n;
int m;
int p[300000];
int q[300000];
int x[300000];
vi res;

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
    for (int i = 0; i < n; i++) {
        int j = i - 1;
        while (j >= 0)
            if (x[j] % x[i] == 0) j -= p[j]; else break;
        p[i] = i - j;
    }
    for (int i = n - 1; i >= 0; i--) {
        int j = i + 1;
        while (j < n)
            if (x[j] % x[i] == 0) j += q[j]; else break;
        q[i] = j - i;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) ans = max (ans, p[i] + q[i]);
    for (int i = 0; i < n; i++)
        if (p[i] + q[i] == ans)
            res.pb (i - p[i] + 2);
    res.resize (unique (all (res)) - res.begin ());
    printf ("%d %d\n", sz (res), ans - 2);
    for (int i = 0; i < sz (res); i++) printf ("%d ", res[i]);
    printf ("\n");
    return 0;
}