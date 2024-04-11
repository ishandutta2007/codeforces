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
int res[2600][2600];
int cnt[26];

string s;

string out (int i, int j) {
    if (i > j) re "";
    if (i == j) re s.substr (i, 1);
    if (res[i + 1][j] == res[i][j]) re out (i + 1, j); else
    if (res[i][j - 1] == res[i][j]) re out (i, j - 1); else
    if (res[i][j] == res[i + 1][j - 1] + 2) re s[i] + out (i + 1, j - 1) + s[j];
}

int main () {
    cin >> s;
    n = sz (s);
    if (n <= 2600) {
        memset (res, 0, sizeof (res));
        for (int i = 0; i < n; i++)
            res[i][i] = 1;
        for (int l = 1; l < n; l++)
            for (int i = 0; i + l < n; i++) {
                int j = i + l;
                res[i][j] = max (res[i + 1][j], res[i][j - 1]);
                if (s[i] == s[j]) res[i][j] = max (res[i][j], res[i + 1][j - 1] + 2);
            }
        string t = out (0, n - 1);
        while (sz (t) > 101) {
            t.erase (0, 1);
            t.erase (sz (t) - 1, 1);
        }
        if (sz (t) == 101) t.erase (50, 1);
        cout << t << endl;
    } else {
        for (int i = 0; i < n; i++) cnt[s[i] - 'a']++;
        for (int i = 0; i < 26; i++)
            if (cnt[i] >= 100) {
                printf ("%s\n", string (100, i + 'a').c_str ());
                re 0;
            }
    }
    return 0;                   
}