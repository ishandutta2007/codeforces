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
int was[40000][100];
int res[40000][100];
int a, b;

int check (int a, int b, int n) {
    if (a == 1) re 0;
    ll c = 1;
    for (int i = 0; i < b; i++) {
        c *= a;
        if (c >= n) re 1;
    }
    re 0;
}

int go (int a, int b, int n) {
    if (check (a, b, n)) re 1;
    if (a >= 40000) re ((n - a) & 1) ? -1 : 1;
    if (was[a][b]) re res[a][b];
    if (b >= 100) re 0;
    was[a][b] = 1;
    re res[a][b] = max (-go (a + 1, b, n), -go (a, b + 1, n));
}

int main() {
    scanf ("%d%d%d", &a, &b, &n);   
    int tmp = go (a, b, n);
    if (tmp == 1) printf ("Masha\n"); else
    if (tmp == -1) printf ("Stas\n"); else printf ("Missing\n");
    return 0;
}