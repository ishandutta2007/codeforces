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

const int INF = 2e9;

int n;
int m;
int res[5001][5001];
int x[5000];
int y[5001];

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
    y[n] = 0;
    for (int i = n - 1; i >= 0; i--) y[i] = y[i + 1] + x[i];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            res[i][j] = INF;
    res[0][0] = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = n - 1; j >= 0; j--)
            res[i][j] = min (res[i][j], res[i][j + 1]);
        int k = n - 1;
        for (int j = n; j > 0; j--) {
            while (k > 0 && y[i] - y[j] < res[i][k]) k--;
            if (y[i] - y[j] >= res[i][k])
                res[j][k + 1] = min (res[j][k + 1], y[i] - y[j]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (res[n][i] < INF)
            ans = i;
    printf ("%d\n", n - ans);
    return 0;
}