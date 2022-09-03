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
vii v[2];

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf ("%d%d", &a, &b); 
        v[a].pb (mp (b, i + 1));
    }
    sort (all (v[0]));
    sort (all (v[1]));
    int i = 0, j = 0;
    while (i < sz (v[0]) && j < sz (v[1])) {
        int tmp = min (v[0][i].fi, v[1][j].fi);
        printf ("%d %d %d\n", v[0][i].se, v[1][j].se, tmp);
        if (v[0][i] < v[1][j]) {
            i++;
            v[1][j].fi -= tmp;
        } else {
            j++;
            v[0][i].fi -= tmp;
        }
    }
    if (i < sz (v[0])) i++;
    if (j < sz (v[1])) j++;
    while (i < sz (v[0])) {
        printf ("%d %d 0\n", v[0][i].se, v[1][j - 1].se);
        i++;
    }
    while (j < sz (v[1])) {
        printf ("%d %d 0\n", v[1][j].se, v[0][i - 1].se);
        j++;
    }
    return 0;
}