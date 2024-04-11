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

int x[200], y[200];
int res[200][3000];
int was[200][3000];

int go (int i, int j) {
    if (j < 0) re 0;
    if (j == 0) re 1;
    if (was[i][j]) re res[i][j];
    was[i][j] = 1;
    int cur = 0;
    for (int k = 0; k < 2 * n; k++)
        if (k / 2 != i / 2 && x[k] == y[i]) cur = (cur + go (k, j - x[k])) % mod;
    re res[i][j] = cur;
}

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf ("%d%d", &x[2 * i], &y[2 * i]);
        if (x[2 * i] == y[2 * i]) x[2 * i + 1] = y[2 * i + 1] = -1; else {
            x[2 * i + 1] = y[2 * i];
            y[2 * i + 1] = x[2 * i];
        }
    }   
    int ans = 0;
    for (int i = 0; i < 2 * n; i++) 
        if (x[i] != -1)
            ans = (ans + go (i, m - x[i])) % mod;
    printf ("%d\n", ans);
    return 0;
}