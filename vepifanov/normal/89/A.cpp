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
int m;
int k;
int x[10000];

int main() {
    scanf ("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
    int ans = 0;
    if (n & 1) {
        int j = x[0];
        for (int i = 0; i < n; i += 2) j = min (j, x[i]);
        int t = m / (n / 2 + 1);
        ans = min ((ll)j, (ll)k * t);
    }
    if (n == 1) ans = min ((ll)x[0], (ll)m * k);
    printf ("%d\n", ans);
    return 0;
}