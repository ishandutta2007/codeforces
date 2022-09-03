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

const int mod = 1000000000 + 7;

int n;
int m;

int was[101][2501], res[101][2501];
int tt;
string s;

int go (int i, int j) {
    if (j < 0) re 0;
    if (i == 0) re int (j == 0);
    if (was[i][j]) re res[i][j];
    was[i][j] = 1;
    int cur = 0;
    for (int k = 0; k < 26; k++)
        (cur += go (i - 1, j - k)) %= mod;
    re res[i][j] = cur;
}

int main () {
    cin >> tt;
    memset (was, 0, sizeof (was));
    for (int it = 0; it < tt; it++) {
        cin >> s;
        n = sz (s);
        int sum = 0;
        for (int i = 0; i < n; i++) sum += s[i] - 'a';
        printf ("%d\n", (go (n, sum) - 1 + mod) % mod);
    }
    return 0;
}