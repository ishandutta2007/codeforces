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
int k;
string s, a, b, c;
pair<int, vs> res[20][2][20][2][20][2];
int was[20][2][20][2][20][2];

pair<int, vs> go (int x, int fx, int y, int fy, int z, int r) {
//  cerr << x << " " << fx << " " << y << " " << z << " " << r << endl;
    if (x == n && y == m && z == k && r == 0) re mp (0, vs (3, ""));
    if (was[x][fx][y][fy][z][r]) re res[x][fx][y][fy][z][r];
    was[x][fx][y][fy][z][r] = 1;
    pair<int, vs> cur = mp (1000000, vs (3, "")), tmp;
    res[x][fx][y][fy][z][r] = cur;
    for (int a = 0; a < 10; a++)
        for (int b = 0; b < 10; b++)
            for (int c = 0; c < 10; c++)
                if ((a + b + r) % 10 == c) {
                    int nr = (a + b + r) / 10;
                    if (a == 0 && b == 0 && y == n) {
                        tmp = go (x, 0, y, 0, z + int (z < k && ::c[z] - '0' == c), nr);
                        tmp.se[2] = tmp.se[2] + char (c + '0');
                        tmp.fi += 1;
                        cur = min (cur, tmp);
                    }
                    if (a == 0 && x == n && fy) {
                        tmp = go (x, 0, y + int (y < m && ::b[y] - '0' == b), 1, z + int (z < k && ::c[z] - '0' == c), nr);
                        tmp.se[1] = tmp.se[1] + char (b + '0');
                        tmp.se[2] = tmp.se[2] + char (c + '0');
                        tmp.fi += 2;
                        cur = min (cur, tmp);
                    }
                    if (b == 0 && y == n && fx) {
                        tmp = go (x + int (x < n && ::a[x] - '0' == a), 1, y, 0, z + int (z < k && ::c[z] - '0' == c), nr);
                        tmp.se[0] = tmp.se[0] + char (a + '0');
                        tmp.se[2] = tmp.se[2] + char (c + '0');
                        tmp.fi += 2;
                        cur = min (cur, tmp);
                    }
                    if (fx && fy) {
                        tmp = go (x + int (x < n && ::a[x] - '0' == a), 1, y + int (y < m && ::b[y] - '0' == b), 1, z + int (z < k && ::c[z] - '0' == c), nr);
                        tmp.se[0] = tmp.se[0] + char (a + '0');
                        tmp.se[1] = tmp.se[1] + char (b + '0');
                        tmp.se[2] = tmp.se[2] + char (c + '0');
                        tmp.fi += 3;
                        cur = min (cur, tmp);
                    }
                }
    re res[x][fx][y][fy][z][r] = cur;
}

int main() {
    cin >> s;
    for (int i = 0; i < sz (s); i++)
        if (s[i] == '+' || s[i] == '=')
            s[i] = ' ';
    stringstream in (s);
    in >> a >> b >> c;
    n = sz (a); m = sz (b); k = sz (c);
    reverse (all (a));
    reverse (all (b));
    reverse (all (c));
    vs res = go (0, 1, 0, 1, 0, 0).se;
    cout << res[0] + "+" + res[1] + "=" + res[2] << endl;
    return 0;
}