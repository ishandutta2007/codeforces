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

string s[1500];
int was[1500][1500];
ii res[1500][1500];
             
int go (int i, int j) {
    int ii = i % n, jj = j % m;
    if (ii < 0) ii += n;
    if (jj < 0) jj += m;
    if (s[ii][jj] == '#') re 0;
    if (was[ii][jj]) {
        if (res[ii][jj] != mp (i, j)) re 1;
        re 0;
    }
    was[ii][jj] = 1;
    res[ii][jj] = mp (i, j);
    re go (i - 1, j) | go (i, j - 1) | go (i + 1, j) | go (i, j + 1);
}

int main () {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (s[i][j] == 'S' && go (i, j)) {
                printf ("Yes\n");
                re 0;
            }
    printf ("No\n");
    return 0;
}