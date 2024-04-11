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
vi v[3];


int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf ("%d", &x);
        if (x > 0) v[0].pb (x);
        if (x == 0) v[1].pb (x);
                if (x < 0) v[2].pb (x);
    }
    if (sz (v[0]) == 0) {
        v[0].push_back (v[2][0]);
        v[2].erase (v[2].begin ());
        v[0].push_back (v[2][0]);
        v[2].erase (v[2].begin ());
    }
    if (sz (v[2]) % 2 == 0) {
        v[1].push_back (v[2][0]);
        v[2].erase (v[2].begin ());
    }
    printf ("%d", sz (v[2]));
    for (int i = 0; i < sz (v[2]); i++) printf (" %d", v[2][i]);
    printf ("\n");
    printf ("%d", sz (v[0]));
    for (int i = 0; i < sz (v[0]); i++) printf (" %d", v[0][i]);
    printf ("\n");
    printf ("%d", sz (v[1]));
    for (int i = 0; i < sz (v[1]); i++) printf (" %d", v[1][i]);
    printf ("\n");
    return 0;
}