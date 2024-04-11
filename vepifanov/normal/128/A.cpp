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

char w[9][9];

int was[8][8][101];

int go (int i, int j, int l) {
    if (i < 0 || j < 0 || i > 7 || j > 7 || l > 100) re 0;
    if (i - l >= 0 && w[i - l][j] == 'S') re 0;
    if (l > 0 && i - l + 1 >= 0 && w[i - l + 1][j] == 'S') re 0;
    if (w[i][j] == 'A') re 1;
    if (was[i][j][l]) re 0;
    was[i][j][l] = 1;
    if (go (i - 1, j, l + 1) || go (i, j - 1, l + 1) || go (i + 1, j, l + 1) || go (i, j + 1, l + 1)) re 1;
    if (go (i - 1, j - 1, l + 1) || go (i + 1, j - 1, l + 1) || go (i - 1, j + 1, l + 1) || go (i + 1, j + 1, l + 1)) re 1;
    if (go (i, j, l + 1)) re 1;
    re 0;
}

int main () {
    for (int i = 0; i < 8; i++) gets (w[i]);
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if (w[i][j] == 'M')
                if (go (i, j, 0)) {
                    printf ("WIN\n");
                    re 0;
                }
    printf ("LOSE\n");
    return 0;
}