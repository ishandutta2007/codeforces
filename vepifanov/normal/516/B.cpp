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
#define prev PREV
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

const int N = 2000;

int n;
int m;
string s[N];
ii q[N * N];

int put (int i, int j, int ni, int nj) {
    if (ni < i) {
        s[i][j] = 'v';
        s[ni][nj] = '^';
    } else
    if (ni > i) {
        s[i][j] = '^';
        s[ni][nj] = 'v';
    } else
    if (nj < j) {
        s[i][j] = '>';
        s[ni][nj] = '<';
    } else {
        s[i][j] = '<';
        s[ni][nj] = '>';
    }
    re 0;
}

int calc (int i, int j) {
    int cur = 0;
    for (int t = 0; t < 4; t++) {
        int ni = i + int (t == 0) - int (t == 1);
        int nj = j + int (t == 2) - int (t == 3);
        if (ni < 0 || nj < 0 || ni >= n || nj >= m || s[ni][nj] != '.') continue;
        cur++;
    }
    re cur; 
}

int main () {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> s[i];
    int l = 0, r = 0, rem = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (s[i][j] == '.') {
                rem++;
                int cnt = calc (i, j);
                if (cnt == 0) {
                    printf ("Not unique\n");
                    re 0;
                }
                if (cnt == 1) q[r++] = mp (i, j);
            }   
    while (l < r) {
        int i = q[l].fi;
        int j = q[l].se;
        l++;
        if (s[i][j] != '.') continue;
        if (calc (i, j) == 0) {
            printf ("Not unique\n");
            re 0;
        }
        int fi, fj;
        for (int t = 0; t < 4; t++) {
            int ni = i + int (t == 0) - int (t == 1);
            int nj = j + int (t == 2) - int (t == 3);
            if (ni < 0 || nj < 0 || ni >= n || nj >= m || s[ni][nj] != '.') continue;
            fi = ni;
            fj = nj;
            break;
        }
        put (i, j, fi, fj);
        for (int t = 0; t < 4; t++) {
            int ni = fi + int (t == 0) - int (t == 1);
            int nj = fj + int (t == 2) - int (t == 3);
            if (ni < 0 || nj < 0 || ni >= n || nj >= m || s[ni][nj] != '.') continue;
            int cnt = calc (ni, nj);
            if (cnt == 0) {
                printf ("Not unique\n");
                re 0;
            }
            if (cnt == 1) q[r++] = mp (ni, nj);
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (s[i][j] == '.') {
                printf ("Not unique\n");
                re 0;
            }
    for (int i = 0; i < n; i++) cout << s[i] << endl;
    return 0;
}