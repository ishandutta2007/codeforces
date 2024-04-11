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
int was[2001][2001][2];
int res[2001][2001][2];
string s;

int go (int i, int j, int f) {
    if (i == n) re int (j == 0);
    if (was[i][j][f]) re res[i][j][f];
    was[i][j][f] = 1;
    int cur = 0;
    if (f == 1) {
        cur = (cur + go (i + 1, j, 1)) % mod;
        cur = (cur + (ll)(s[i] - 'a') * go (i + 1, j, 0)) % mod;
    } else {
        cur = (cur + go (i, j, 1)) % mod;
        int last = -1;
        for (int k = 0; i + k < n; k++) {
            int tmp = (k + 1) * (n - i - k);
            if (tmp > j) break;
            last = k;
            cur = (cur + (ll)('z' - s[i + k]) * go (i + k + 1, j - tmp, 0)) % mod;
        }
        for (int k = n - i - 1; k > last; k--) {
            int tmp = (k + 1) * (n - i - k);
            if (tmp > j) break;
            cur = (cur + (ll)('z' - s[i + k]) * go (i + k + 1, j - tmp, 0)) % mod;
        }
    }   
    re res[i][j][f] = cur;
}

int main () {
    cin >> n >> m >> s;
    cout << go (0, m, 0) << endl;
    return 0;
}