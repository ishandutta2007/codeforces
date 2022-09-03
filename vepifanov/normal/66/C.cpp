#include <cstdio>
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

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < n; i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define y0 y3487465
#define y1 y8687969

typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) {
    re x > 0 ? x : -x;
}

int n;
int m;
string s;
map<string, int> file;
vs v;

int main() {
    int af = 0, bf = 0;
    while (cin >> s) {
        while (s[sz (s) - 1] != '\\') s.erase (sz (s) - 1, 1);
        for (int j = 0; s[sz (s) - 2] != ':'; j++) {
            file[s]++;
            af = max (af, file[s]);
            v.pb (s);
            s.erase (sz (s) - 1, 1);
            while (s[sz (s) - 1] != '\\') s.erase (sz (s) - 1, 1);
        }
    }
    sort (all (v));
    v.resize (unique (all (v)) - v.begin ());
    for (int i = 0; i < sz (v); i++) {
        int cur = 0;
        for (int j = 0; j < sz (v); j++)
            if (sz (v[i]) < sz (v[j]) && v[j].substr (0, sz (v[i])) == v[i])
                cur++;
        bf = max (bf, cur);
    }
    printf ("%d %d\n", bf, af);
    return 0;
}