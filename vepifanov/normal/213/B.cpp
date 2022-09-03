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

int x[10];
int was[10][101];
int res[10][101];
int cnk[101][101];

int go (int i, int j) {
    if (was[i][j]) re res[i][j];
    was[i][j] = 1;
    int cur = 0;
    if (i == 0) {
        for (int k = x[i]; k <= n - j; k++) {
            int tmp = 0;
            if (j > 0 && k == 0) tmp = 1; else
            if (j > 0 && k > 0) tmp = (cnk[j + k][k] - cnk[j + k - 1][k - 1] + mod) % mod;
            (cur += tmp) %= mod;
        }
    } else {
        for (int k = x[i]; k <= n - j; k++) {
            int tmp = go (i - 1, j + k);
            tmp = ((ll)tmp * cnk[j + k][k]) % mod;
            (cur += tmp) %= mod;
        }
    }   
    re res[i][j] = cur;
}

int main () {
    cnk[0][0] = 1;
    for (int i = 0; i < 100; i++)
        for (int j = 0; j <= i; j++) {
            (cnk[i + 1][j] += cnk[i][j]) %= mod;
            (cnk[i + 1][j + 1] += cnk[i][j]) %= mod;
        }   
    scanf ("%d", &n);
    for (int i = 0; i < 10; i++) scanf ("%d", &x[i]);
    printf ("%d\n", go (9, 0));
    return 0;
}