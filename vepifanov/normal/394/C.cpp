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
int g[1000][1000];
int cnt[3];
int q[1000];

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            int x;
            scanf ("%d", &x);
            cnt[x % 10 + x / 10]++;
        }
    int rem = n * m;
    for (int j = 0; rem; j = (j + 1) % m)
        if (q[j] < n) {
            if (cnt[2] >= 1) {
                g[q[j]++][j] = 11;
                cnt[2]--;
            } else
            if (cnt[1] >= 2 && q[j] + 2 <= n) {
                g[q[j]++][j] = 10;
                g[q[j]++][j] = 01;
                cnt[1] -= 2;
                rem--;
            } else
            if (cnt[1] >= 1) {
                g[q[j]++][j] = 10;
                cnt[1]--;
            } else {
                g[q[j]++][j] = 00;
                cnt[0]--;
            }
            rem--;
        }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf ("%02d ", g[i][j]);
        printf ("\n");
    }
    return 0;
}