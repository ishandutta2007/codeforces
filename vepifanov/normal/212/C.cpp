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
int m, a, b;

string s;
int x[100];
int was[100][2][2];
ll res[100][2][2];

int get (int a, int b, int c) {
    if (a == 0 && b == 1) re 0;
    if (b == 0 && c == 1) re 1;
    re b;
}

ll go (int a, int b, int i) {
    if (i == n) {
        if (get (a, b, ::a) == x[n - 1] && get (b, ::a, ::b) == x[0]) re 1;
        re 0;
    }
    if (was[i][a][b]) re res[i][a][b];
    was[i][a][b] = 1;
    ll cur = 0;
    for (int c = 0; c < 2; c++)
        if (get (a, b, c) == x[i - 1])
            cur += go (b, c, i + 1);
    re res[i][a][b] = cur;
}

int main () {
    cin >> s;
    n = sz (s);
    for (int i = 0; i < n; i++) x[i] = s[i] - 'A';
    ll ans = 0;
    for (a = 0; a < 2; a++)
        for (b = 0; b < 2; b++) {
            memset (was, 0, sizeof (was));
            ans += go (a, b, 2);
        }   
    cout << ans << endl;
    return 0;
}