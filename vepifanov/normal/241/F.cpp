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
int m, t;

string s[100];
int x1, y1, x2, y2;
string w;
int wi[26], wj[26];

int go (int ax, int ay, int bx, int by) {
    if (ax == bx && ay == by) re 0;
    int k = 1;
    if (s[ax][ay] >= '1' && s[ax][ay] <= '9') k = s[ax][ay] - '0';
    if (t >= k) {
        t -= k;
        if (ax < bx) ax++; else
        if (ax > bx) ax--; else
        if (ay < by) ay++; else
        if (ay > by) ay--;
        re go (ax, ay, bx, by);
    } else {
        printf ("%d %d\n", ax + 1, ay + 1);
        re 1;
    }   
}

int main () {
    cin >> n >> m >> t;
    for (int i = 0; i < n; i++) cin >> s[i];
    cin >> x1 >> y1 >> w >> x2 >> y2; x1--; y1--; x2--; y2--;
    w = "$" + w + "#";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (s[i][j] >= 'a' && s[i][j] <= 'z') {
                int o = s[i][j] - 'a';
                wi[o] = i;
                wj[o] = j;
            }
    for (int i = 0; i + 1 < sz (w); i++) {
        int ax, ay, bx, by;
        if (w[i] == '$') { ax = x1; ay = y1; } else { ax = wi[w[i] - 'a']; ay = wj[w[i] - 'a']; }
        if (w[i + 1] == '#') { bx = x2; by = y2; } else { bx = wi[w[i + 1] - 'a']; by = wj[w[i + 1] - 'a']; }
        if (go (ax, ay, bx, by)) re 0;
    }
    printf ("%d %d\n", x2 + 1, y2 + 1);
    return 0;
}