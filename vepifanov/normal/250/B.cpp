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

int main () {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s, t;
        cin >> s;
        vs v, w, u;
        for (int j = 0; j < sz (s); j++)
            if (s[j] == ':')
                s[j] = ' ';
        for (int j = 0; j + 1 < sz (s); j++)
            if (s[j] == ' ' && s[j + 1] == ' ') {
                stringstream in (s.substr (0, j));
                while (in >> t) v.pb (t);
                stringstream in2 (s.substr (j, sz (s) - j));
                while (in2 >> t) w.pb (t);
                for (int k = 0; k < 8 - sz (v) - sz (w); k++) u.pb ("");
                for (int k = 0; k < sz (u); k++) v.pb (u[k]);
                for (int k = 0; k < sz (w); k++) v.pb (w[k]);
                break;
            }
        if (sz (v) == 0) {
            stringstream in (s);
            while (in >> t) v.pb (t);
        }
        for (int j = 0; j < sz (v); j++)
            while (sz (v[j]) < 4) v[j] = "0" + v[j];
        for (int j = 0; j < sz (v); j++) {
            if (j > 0) cout << ":";
            cout << v[j];
        }
        cout << endl;
    }
    return 0;
}