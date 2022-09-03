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
set<int> all;
vector<pair<int, vi> > q;
int x[50];

int main () {
    scanf ("%d%d", &n, &m); m++;
    for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
    q.pb (mp (0, vi (0)));
    for (int i = 0; i < n && sz (q) < m; i++) {
        int k = sz (q);
        for (int j = 0; j < k && sz (q) < m; j++)
            if (all.find (q[j].fi + x[i]) == all.end ()) {
                vi v = q[j].se;
                int tmp = q[j].fi + x[i];
                all.insert (tmp);
                v.pb (x[i]);
                q.pb (mp (tmp, v));
            }
    }
    for (int i = 1; i < sz (q); i++) {
        printf ("%d ", sz (q[i].se));
        for (int j = 0; j < sz (q[i].se); j++)
            printf ("%d ", q[i].se[j]);
        printf ("\n");
    }
    return 0;
}