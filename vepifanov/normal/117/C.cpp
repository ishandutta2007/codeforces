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
char g[5001][5001];
int was[5001];

int go (int x, int p) {
    was[x] = 1;
    for (int i = 0; i < n; i++)
        if (g[x][i] == '1') {
            if (p != -1 && g[i][p] == '1') {
                printf ("%d %d %d\n", x + 1, i + 1, p + 1);
                re 1;
            }
            if (!was[i] && go (i, x)) re 1;
        }
    re 0;
}

int main () {
    scanf ("%d", &n);   
    gets (g[0]);
    for (int i = 0; i < n; i++) gets (g[i]);
    for (int i = 0; i < n; i++)
        if (!was[i])
            if (go (i, -1)) re 0;
    printf ("-1\n");
    return 0;
}