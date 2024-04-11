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
int m, x, y;

int f[1000][2];
string s[1000];
int was[1000][2];
int res[1000][2];

int go (int i, int j) {
    if (i == m) re 0;
    if (was[i][j]) re res[i][j];
    was[i][j] = 1;
    int cur = 1e9, tmp = 0;
    for (int k = i; k < m; k++) {
        tmp += f[k][j];
        if (k - i + 1 >= x && k - i + 1 <= y) cur = min (cur, go (k + 1, 1 - j) + tmp);
    }
    re res[i][j] = cur;
}

int main () {
    cin >> n >> m >> x >> y;
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (s[i][j] == '#')
                f[j][0]++;
            else
                f[j][1]++;  
    printf ("%d\n", min (go (0, 0), go (0, 1)));
    return 0;
}