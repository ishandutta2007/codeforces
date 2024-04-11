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

ii v[8];
int p[8];

ii operator- (ii a, ii b) { re mp (a.fi - b.fi, a.se - b.se); }
ii operator+ (ii a, ii b) { re mp (a.fi + b.fi, a.se + b.se); }
int operator* (ii a, ii b) { re a.fi * b.fi + a.se * b.se; }

ii get (ii p1, ii p2, ii p3, ii p4) {
    ii a = p2 - p1, b = p4 - p1;
    if (p3 - p4 == a && p3 - p2 == b && (a * b) == 0) re mp (a * a, b * b);
    re mp (-1, -1);
}

int main () {
    for (int i = 0; i < 8; i++) {
        p[i] = i;
        scanf ("%d%d", &v[i].fi, &v[i].se);
    }   
    do {
        ii a = get (v[p[0]], v[p[1]], v[p[2]], v[p[3]]);
        ii b = get (v[p[4]], v[p[5]], v[p[6]], v[p[7]]);
        if (a.fi != -1 && b.fi != -1 && a.fi == a.se) {
            printf ("YES\n");
            for (int i = 0; i < 4; i++) printf ("%d ", p[i] + 1);
            printf ("\n");
            for (int i = 0; i < 4; i++) printf ("%d ", p[i + 4] + 1);
            printf ("\n");
            re 0;
        }
    } while (next_permutation (p, p + 8));
    printf ("NO\n");
    return 0;
}