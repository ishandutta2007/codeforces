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
int x[5000];
int p[5000][5000];
int q[5000][5000];

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
    for (int i = 0; i < n; i++) {
        int cur = 0;
        for (int j = i + 1; j < n; j++) {
            cur += int (x[i] > x[j]);
            p[i][j] = cur;
        }
        cur = 0;
        for (int j = i - 1; j >= 0; j--) {
            cur += int (x[i] > x[j]);
            q[j][i] = cur;
        }
    }
    int ans = 1e9, sum = 0, cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            sum += int (x[i] > x[j]);
//          printf ("%d %d = %d %d %d %d\n", i, j, p[i][j], q[i][j], (j - i) - p[i][j], (j - i) - q[i][j]);
            int tmp = q[i + 1][j] - ((j - i - 1) - q[i + 1][j]) - p[i][j - 1] + ((j - i - 1) - p[i][j - 1]) - int (x[i] > x[j]) + int (x[i] < x[j]);
            if (tmp < ans) {
                ans = tmp;
                cnt = 1;
            } else
            if (tmp == ans) cnt++;
        }
    printf ("%d %d\n", ans + sum, cnt);
    return 0;
}