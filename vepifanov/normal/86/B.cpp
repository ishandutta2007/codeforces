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
char w[1001][1001];
int col[1001][1001];
int was[10];

int go (int i, int j, int k) {
    if (i < 0 || j < 0 || i >= n || j >= m || w[i][j] == '#' || w[i][j] == '$') re 0;
    if (col[i][j] != k && w[i][j] != '.') { was[w[i][j] - '0'] = 1; re 0; }
    if (col[i][j] != k) re 0;
    w[i][j] = '$';
    go (i - 1, j, k);
    go (i, j - 1, k);
    go (i + 1, j, k);       
    go (i, j + 1, k);
    re 0;
}

int go2 (int i, int j, int k, char c) {
    if (i < 0 || j < 0 || i >= n || j >= m || w[i][j] != '$' || col[i][j] != k) re 0;
    w[i][j] = c;
    go2 (i - 1, j, k, c);
    go2 (i, j - 1, k, c);
    go2 (i + 1, j, k, c);       
    go2 (i, j + 1, k, c);
    re 0;
}

int main() {
    scanf ("%d%d", &n, &m); 
    gets (w[0]);
    for (int i = 0; i < n; i++) gets (w[i]);
    int r = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (w[i][j] == '.' && !col[i][j])
                if (j + 1 < m && !col[i][j + 1] && w[i][j + 1] == '.') {
                    r++;
                    col[i][j] = col[i][j + 1] = r;
                } else
                if (i + 1 < n && !col[i + 1][j] && w[i + 1][j] == '.') {
                    r++;
                    col[i][j] = col[i + 1][j] = r;
                } else
                if (j - 1 >= 0 && w[i][j - 1] == '.')
                    col[i][j] = col[i][j - 1];
                else
                if (i - 1 >= 0 && w[i - 1][j] == '.') 
                    col[i][j] = col[i - 1][j];
                else    
                if (j + 1 < m && w[i][j + 1] == '.')
                    col[i][j] = col[i][j + 1];
                else
                if (i + 1 < n && w[i + 1][j] == '.')
                    col[i][j] = col[i + 1][j];
                else {
                    printf ("-1\n");
                    re 0;
                }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (w[i][j] == '.') {
                for (int t = 0; t < 10; t++) was[t] = 0;
                go (i, j, col[i][j]);
                for (int t = 0; t < 10; t++)
                    if (!was[t]) {
                        go2 (i, j, col[i][j], t + '0');
                        break;
                    }
            }
    for (int i = 0; i < n; i++) printf ("%s\n", w[i]);
    return 0;
}