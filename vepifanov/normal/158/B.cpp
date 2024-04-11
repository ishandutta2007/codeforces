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
int s[4];
int ans;

int add (int a, int b, int c, int d) {
    int k = n + 1;
    if (a != 0) k = min (k, s[0] / a);
    if (b != 0) k = min (k, s[1] / b);
    if (c != 0) k = min (k, s[2] / c);
    if (d != 0) k = min (k, s[3] / d);
    ans += k;
    s[0] -= k * a;
    s[1] -= k * b;
    s[2] -= k * c;
    s[3] -= k * d;
    re 0;
}

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf ("%d", &x);
        s[x - 1]++;
    }
    ans = 0;
    add (0, 0, 0, 1);
    add (1, 0, 1, 0);
    add (0, 0, 1, 0);
    add (0, 2, 0, 0);
    add (2, 1, 0, 0);
    add (1, 1, 0, 0);
    add (0, 1, 0, 0);
    add (4, 0, 0, 0);
    add (3, 0, 0, 0);
    add (2, 0, 0, 0);
    add (1, 0, 0, 0);
    printf ("%d\n", ans);
    return 0;
}