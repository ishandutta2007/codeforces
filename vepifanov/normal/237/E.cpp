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
vi v[130];
int g[130][130];
int w[130][130];
int mark[130];
int d[130];
int p[130], prev[130];

int addedge (int a, int b, int f, int c) {
    v[a].pb (b);
    v[b].pb (a);
    g[a][b] = f;
    w[a][b] = c;
    g[b][a] = 0;
    w[b][a] = -c;
    re 0;
}

int go (int S, int T) {
    memset (mark, 0, sizeof (mark));
    for (int i = 0; i < n + 28; i++) {
        d[i] = 1e9;
    }
    d[S] = 0;
    mark[S] = 1;
    while (true) {
        int k = -1;
        for (int i = 0; i < n + 28; i++)
            if (mark[i] == 1 && (k == -1 || d[k] > d[i]))
                k = i;
        if (k == -1 || k == T) break;
        mark[k] = 2;
        for (int i = 0; i < sz (v[k]); i++) {
            int y = v[k][i];
            if (g[k][y] == 0) continue;
            int z = w[k][y] + p[k] - p[y];
            if (d[y] > d[k] + z) {
                d[y] = d[k] + z;
                mark[y] = 1;
                prev[y] = k;
            }
        }
    }
    if (!mark[T]) re -1;
    int res = d[T] - p[S] + p[T];
    for (int i = 0; i < n + 28; i++)
        if (mark[i] < 2)
            p[i] += d[T];
        else    
            p[i] += d[i];
    while (T != S) {            
        int k = prev[T];
                g[k][T]--;
                g[T][k]++;
                T = k;
    }
    re res;
}

int main () {
    string s, t;
    cin >> s >> n;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> t >> k;
        addedge (0, i + 1, k, i + 1);
        for (int j = 0; j < 26; j++) {
            int tmp = 0;
            for (int u = 0; u < sz (t); u++) 
                tmp += int (t[u] - 'a' == j);
            if (tmp > 0) addedge (i + 1, 1 + n + j, tmp, 0);
        }
    }
    for (int j = 0; j < 26; j++) {
        int tmp = 0;
        for (int u = 0; u < sz (s); u++) 
            tmp += int (s[u] - 'a' == j);
        if (tmp > 0) addedge (1 + n + j, n + 26 + 1, tmp, 0);
    }
    int ans = 0;
    for (int i = 0; i < sz (s); i++) {
        int tmp = go (0, n + 26 + 1);
        if (tmp == -1) {
            printf ("-1\n");
            re 0;
        }
        ans += tmp;
    }
    printf ("%d\n", ans);
    return 0;
}