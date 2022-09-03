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

char h[1001000];

vi v[500000];
string s[500000];
int prev[500000];
string w[500];
int ans;

int go (int x, int y) {
    if (s[x] == w[y])
        if (y + 1 == m) ans++; else y++;
    for (int i = 0; i < sz (v[x]); i++)
        go (v[x][i], y);
    re 0;
}

int main () {
    gets (h);
    int r = 1;
    s[0] = "";
    for (int i = 0; h[i]; i++)
        if (h[i] == '<' || h[i] == '>')
            h[i] = ' ';
    stringstream in (h);
    string t;
    int x = 0;
    while (in >> t)
        if (t[0] == '/') x = prev[x]; else
        if (t[sz (t) - 1] == '/') {
            t.erase (sz (t) - 1, 1);
            s[r] = t;
            prev[r] = x;
            v[x].pb (r);
            r++;
        } else {
            s[r] = t;
            prev[r] = x;
            v[x].pb (r);
            x = r;
            r++;
        }
    scanf ("%d", &n);
    gets (h);
    for (int i = 0; i < n; i++) {
        gets (h);
        stringstream in (h);
        string t;
        m = 0;
        ans = 0;
        while (in >> t) w[m++] = t;
        go (0, 0);
        printf ("%d\n", ans);
    }
    return 0;
}