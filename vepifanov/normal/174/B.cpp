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
string s;
int can[400001], prev[400001];

int good (string s) {
    int ok = 0;
    for (int i = 0; i < sz (s); i++)
        if (s[i] == '.') {
            ok++;
            s[i] = ' ';
        }
    if (ok != 1 || s[0] == ' ' || s[sz (s) - 1] == ' ') re 0;
    stringstream in (s);
    string a, b;
    in >> a >> b;
    if (sz (a) > 8 || sz (b) > 3) re 0;
    re 1;
}

int out (int x) {
    if (x == 0) re 0;
    out (x - prev[x]);
    printf ("%s\n", s.substr (x - prev[x], prev[x]).c_str ());
    re 0;
}

int main () {
    cin >> s;
    memset (can, 0, sizeof (can));
    can[0] = 1;
    for (int i = 0; i < sz (s); i++)
        if (can[i])
            for (int j = 3; j <= 12 && i + j <= sz (s); j++)
                if (good (s.substr (i, j))) {
                    can[i + j] = 1;
                    prev[i + j] = j;
                }   
    if (can[sz (s)]) {
        printf ("YES\n");
        out (sz (s));
    } else printf ("NO\n");
    return 0;
}