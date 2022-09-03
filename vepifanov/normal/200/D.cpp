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
string f[1000];
map<string, string> tp;
vs fv[1000];
vs v;
char h[100000];

int main () {
    scanf ("%d", &n);
    gets (h);
        for (int i = 0; i < n; i++) {
            gets (h);
            for (int j = 0; h[j]; j++)
                if (h[j] == '(' || h[j] == ')' || h[j] == ',')
                    h[j] = ' ';
            stringstream in (h);
            string t;
            in >> t;
            in >> f[i];
            while (in >> t) fv[i].pb (t);
        }
    scanf ("%d", &m);
    gets (h);
        for (int i = 0; i < m; i++) {
            gets (h);
            for (int j = 0; h[j]; j++)
                if (h[j] == '(' || h[j] == ')' || h[j] == ',')
                    h[j] = ' ';
            stringstream in (h);
            string s, t;
            in >> s >> t;
            tp[t] = s;
        }
    scanf ("%d", &m);
    gets (h);
        for (int i = 0; i < m; i++) {
            gets (h);
            for (int j = 0; h[j]; j++)
                if (h[j] == '(' || h[j] == ')' || h[j] == ',')
                    h[j] = ' ';
            stringstream in (h);
            string t, cf;
            in >> cf;
            v.clear ();
            while (in >> t) v.pb (tp[t]);
            int ans = 0;
            for (int j = 0; j < n; j++)
                if (cf == f[j] && sz (fv[j]) == sz (v)) {
                    int ok = 1;
                    for (int t = 0; t < sz (v); t++)
                        if (fv[j][t] != "T" && fv[j][t] != v[t]) {
                            ok = 0;
                            break;
                        }
                    ans += ok;
                }
            printf ("%d\n", ans);
        }
    return 0;
}