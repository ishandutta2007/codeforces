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

char g[10000][10000];
vi v[10000];
map<string, int> all;
string name[10000];
int was[10000];

int get (string s) {
    if (all.find (s) != all.end ()) re all[s];
    name[m] = s;
    all[s] = m++;
    re m - 1;
}

int main () {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s, t;
        cin >> s >> t;
        int a = get (s);
        int b = get (t);
        v[a].pb (b);
        v[b].pb (a);
        g[a][b] = g[b][a] = 1;
    }
    printf ("%d\n", m);
    for (int i = 0; i < m; i++) {
        memset (was, 0, sizeof (was));
        for (int j = 0; j < sz (v[i]); j++) was[v[i][j]] = 1;
        int cur = 0, cnt = 0;
        for (int j = 0; j < m; j++)
            if (i != j && !g[i][j]) {
                int s = 0;
                for (int k = 0; k < sz (v[j]); k++) s += was[v[j][k]];
                if (s > cur) { cur = s; cnt = 0; }
                cnt += int (s == cur);
            }
        printf ("%s %d\n", name[i].c_str (), cnt);
    }
    return 0;
}