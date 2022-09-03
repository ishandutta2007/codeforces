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

const int N = 500000;

int n;
int m;
int can[51][N + 1];
int x[50];

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
    can[0][0] = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= N; j++)
            if (can[i][j]) {
                can[i + 1][j] = 1;
                can[i + 1][j + x[i]] = 1;
            }
    int cur = 0, ans = 0;
    while (true) {
        int tmp = 0;
        for (int i = 1; i <= m && cur + i <= N; i++)
            if (can[n][cur + i])
                tmp = i;
        if (tmp == 0) break;
        cur += tmp;
        ans++;
    }
    printf ("%d %d\n", cur, ans);
    return 0;
}