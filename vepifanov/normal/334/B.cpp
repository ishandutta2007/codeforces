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
vi v, w;
set<ii> all;

int main () {
    for (int i = 0; i < 8; i++) {
        int x, y;
        scanf ("%d%d", &x, &y);
        all.insert (mp (x, y));
        v.pb (x);
        w.pb (y);
    }
    sort (all (v));
    sort (all (w));
    v.resize (unique (all (v)) - v.begin ());
    w.resize (unique (all (w)) - w.begin ());
    if (sz (v) != 3 || sz (w) != 3) printf ("ugly\n"); else {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (int (i != 1 || j != 1) != int (all.find (mp (v[i], w[j])) != all.end ())) {
                    printf ("ugly\n");
                    re 0;
                }   
        printf ("respectable\n");
    }
    return 0;
}