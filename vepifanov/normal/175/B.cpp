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

map<string, int> all;
vector<pair<string, int> > res;

int main () {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        int t;
        cin >> s >> t;
        all[s] = max (all[s], t);
    }
    for (map<string, int>::iterator it = all.begin (); it != all.end (); it++)
        res.pb (mp (it->fi, it->se));
    m = sz (res);
    printf ("%d\n", m);
    for (int i = 0; i < m; i++) {
        int ok = 0;
        for (int j = 0; j < m; j++)
            if (res[i].se >= res[j].se)
                ok++;
        printf ("%s ", res[i].fi.c_str ());
        if (100 * ok < 50 * m) printf ("noob"); else
        if (100 * ok < 80 * m) printf ("random"); else
        if (100 * ok < 90 * m) printf ("average"); else
        if (100 * ok < 99 * m) printf ("hardcore"); else printf ("pro");
        printf ("\n");
    }
    return 0;
}