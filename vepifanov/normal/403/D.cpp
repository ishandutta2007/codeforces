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

const int N = 1000;
const int M = 50;

const int mod = 1000000000 + 7;

int n;
int m;

int res[M + 1][N + 1];
int sum[M + 1][N + 1];
int f[M + 1];

int main () {
    f[0] = 1;
    for (int i = 1; i <= M; i++) f[i] = ((ll)f[i - 1] * i) % mod;
    res[0][0] = 1;
    for (int i = 0; i <= N; i++) sum[0][i] = 1;
    for (int t = 1; t <= N; t++) {
        for (int j = 1; j <= M; j++)
            for (int i = t; i <= N; i++)
                res[j][i] = (res[j][i] + sum[j - 1][i - t]) % mod;
        for (int j = 0; j <= M; j++) {
            int cur = 0;
            for (int i = 0; i <= N; i++) {
                cur = (cur + res[j][i]) % mod;
                sum[j][i] = cur;
            }
        }   
    }
    int tt;
    scanf ("%d", &tt);
    for (int it = 0; it < tt; it++) {
        scanf ("%d%d", &n, &m);
        if (m > M) printf ("0\n"); else {
            int cur = ((ll)sum[m][n] * f[m]) % mod;
            printf ("%d\n", cur);
        }   
    }
    return 0;
}