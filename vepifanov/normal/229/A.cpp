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
string s[100];

int g[10000];

int main () {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < n; i++)
        if (s[i] == string (m, '0')) {
            printf ("-1\n");
            re 0;
        }
    for (int i = 0; i < n; i++) {
        vi v;
        for (int j = 0; j < m; j++)
            if (s[i][j] == '1')
                v.pb (j);
        int s = v[0], t = v[sz (v) - 1];
        v.pb (t - m);
        v.pb (s + m);
        sort (all (v));
        int k = 0;
        for (int j = 0; j < m; j++) {
            while (v[k + 1] <= j) k++;
            g[j] += min (j - v[k], v[k + 1] - j);
        }
    }
    int res = 1e9;
    for (int j = 0; j < m; j++) res = min (res, g[j]);
    printf ("%d\n", res);
    return 0;
}