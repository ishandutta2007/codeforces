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
#define next NEXT
                         
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
int x[100000];
int was[1 << 20];
int last[20];
int next[100000][20];

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
    for (int i = 0; i < 20; i++) last[i] = n;
    for (int i = n - 1; i >= 0; i--)
        for (int j = 0; j < 20; j++) {
            if ((x[i] >> j) & 1)
                last[j] = i;
                next[i][j] = last[j];
        }
    for (int i = 0; i < n; i++) {
        int j = i, cur = 0;
        while (j < n) {
            cur |= x[j];
            was[cur] = 1;
            int nj = n;
            for (int k = 0; k < 20; k++)
                if (((cur >> k) & 1) == 0)
                    nj = min (nj, next[j][k]);
            j = nj;
        }
    }
    int ans = 0;
    for (int i = 0; i < (1 << 20); i++) ans += was[i];
    printf ("%d\n", ans);
    return 0;
}