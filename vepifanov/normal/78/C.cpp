#include <cstdio>
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

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < n; i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define y0 y3487465
#define y1 y8687969

typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) {
    re x > 0 ? x : -x;
}

int n;
int m, k;
map<int, int> all;

int go (int n) {
    if (all.count (n)) re all[n];
    vi v;
    for (int i = 1; i * i <= n; i++)
        if (n % i == 0) {
            int a = i, b = n / i;
            if (b > 1 && a >= k) v.pb ((b & 1) * go (a));
            if (a > 1 && b >= k) v.pb ((a & 1) * go (b));
        }
    sort (all (v));
    v.resize (unique (all (v)) - v.begin ());
    int res = 0;
    if (sz (v) && v[0] == 0)
        for (int i = 0; i < sz (v); i++)
            if (i + 1 == sz (v) || v[i + 1] > v[i] + 1) {
                res = v[i] + 1;
                break;
            }
    re all[n] = res;
}

int main() {
    scanf ("%d%d%d", &n, &m, &k);
    if ((n & 1) && go (m)) printf ("Timur\n"); else printf ("Marsel\n");
    return 0;
}