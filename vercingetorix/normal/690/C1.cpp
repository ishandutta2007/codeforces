#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <sstream>
#include <cmath>
#include <ctime>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector< vector<int> > vvi;
typedef vector<ll> vl;
typedef vector< vector<ll> > vvl;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define forv(i, v) forn(i, v.size())
#define all(v) v.begin(), v.end()
#define mp make_pair
#define pb push_back

vi p;
int n, m;

int up(int x) {
    if (p[x] != x) p[x] = up(p[x]);
    return p[x];
}

void join(int x, int y) {
    p[x] = y;
}

int main() {
#ifdef NEREVAR_PROJECT
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> n >> m;
    p = vi(n);
    forn(i, n) {
        p[i] = i;
    }
    if (m != n - 1) {
        cout << "no\n";
        return 0;
    }
    forn(i, m) {
        int x, y; cin >> x >> y;
        x--, y--;
        x = up(x);
        y = up(y);
        join(x, y);
    }
    forn(i, n) {
        if (up(i) != up(0)) {
            cout << "no\n";
            return 0;
        }
    }
    cout << "yes\n";
    return 0;
}