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
int w1[100000], w2[100000], f[100000];
vi v[100000], rv[100000];

int go1 (int x) {
    w1[x] = 1;
    for (int i = 0; i < sz (v[x]); i++)
        if (!w1[v[x][i]])
            go1 (v[x][i]);
    re 0;
}

int go2 (int x) {
    w2[x] = 1;
    if (f[x] == 1) re 0;
    for (int i = 0; i < sz (rv[x]); i++)
        if (!w2[rv[x][i]])
            go2 (rv[x][i]);
    re 0;
}

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf ("%d", &f[i]);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf ("%d%d", &a, &b); a--; b--;
        v[a].pb (b);
        rv[b].pb (a);
    }
    for (int i = 0; i < n; i++)
        if (f[i] == 1 && !w1[i])
            go1 (i);
        else
        if (f[i] == 2 && !w2[i])    
            go2 (i);
    for (int i = 0; i < n; i++) printf ("%d\n", w1[i] & w2[i]);
    return 0;
}