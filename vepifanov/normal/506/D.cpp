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
#include <unordered_map>

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
#define prev PREV
                         
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

unordered_map<int, int> p[100000];
unordered_map<int, int> res[100000];
vi v[100000];

int gp (int x, int c) {
    if (p[x].find (c) != p[x].end ()) {
        if (p[x][c] != x) p[x][c] = gp (p[x][c], c);
        re p[x][c];
    }
    re x;
}

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf ("%d%d%d", &a, &b, &c); a--; b--;
        v[a].pb (c);
        v[b].pb (c);
        int pa = gp (a, c);
        int pb = gp (b, c);
        if (rand () & 1)
            p[pa][c] = pb;
        else
            p[pb][c] = pa;  
    }
    for (int i = 0; i < n; i++) {
        sort (all (v[i]));
        v[i].resize (unique (all (v[i])) - v[i].begin ());
    }
    scanf ("%d", &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf ("%d%d", &a, &b); a--; b--;
        if (a > b) swap (a, b);
        if (sz (v[a]) < sz (v[b])) swap (a, b);
        if (res[a].find (b) != res[a].end ()) printf ("%d\n", res[a][b]); else {
            int cur = 0;
            for (int t = 0; t < sz (v[b]); t++) 
                cur += int (gp (a, v[b][t]) == gp (b, v[b][t]));
            res[a][b] = cur;
            printf ("%d\n", cur);
        }
    }
    return 0;
}