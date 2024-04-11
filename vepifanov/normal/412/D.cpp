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

const int N = 500000;

int n;
int m;

int was[30000];
set<int> all[30000];
int q[N];
int p[30000];

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf ("%d%d", &a, &b); a--; b--;
        all[a].insert (b);
    }
    for (int i = 0; i < n; i++) p[i] = i;
    int l = 0, r = 0;
    for (int i = 0; i + 1 < n; i++) {
        q[r++] = i;
        was[i] = 1;
    }   
    while (l < r) {
        int x = q[l++];
        was[x] = 0;
        if (all[p[x]].find (p[x + 1]) != all[p[x]].end ()) {
            swap (p[x], p[x + 1]);
            if (x > 0 && !was[x - 1]) {
                was[x - 1] = 1;
                q[r++] = x - 1;
            }
            if (x + 2 < n && !was[x + 1]) {
                was[x + 1] = 1;
                q[r++] = x + 1;
            }
        }
    }
    for (int i = 0; i < n; i++) printf ("%d ", p[i] + 1);
    printf ("\n");
    return 0;
}