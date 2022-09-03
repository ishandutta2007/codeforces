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

int g[300][300];
int q[300], res[300], pos[300];

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        for (int j = 0; j < n; j++) {
            scanf ("%d", &x); x--;
            g[i][x] = j;
        }
    }
    for (int i = 0; i < n; i++) {
        int x;
        scanf ("%d", &x); x--;
        q[x] = i;
    }
    for (int i = 0; i < n; i++) {
        res[i] = -1;
        pos[i] = -1;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            int cur = -1;
            for (int k = 0; k <= i; k++)
                if (k != j && (cur == -1 || q[cur] > q[k]))
                    cur = k;
            if (cur == -1) continue;
            if (pos[j] == -1 || g[j][pos[j]] > g[j][cur]) {
                res[j] = i;
                pos[j] = cur;
            }   
        }
    for (int i = 0; i < n; i++) printf ("%d ", res[i] + 1);
    printf ("\n");
    return 0;
}