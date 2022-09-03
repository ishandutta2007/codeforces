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
int g[5][5];
int p[5];

int main () {
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            scanf ("%d", &g[i][j]);
    for (int i = 0; i < 5; i++) p[i] = i;
    int ans = -1;
    do {
        int cur = 0;
        for (int i = 0; i < 5; i++)
            for (int j = i; j + 1 < 5; j += 2)
                cur += g[p[j]][p[j + 1]] + g[p[j + 1]][p[j]];
        ans = max (ans, cur);
    } while (next_permutation (p, p + 5));
    printf ("%d\n", ans);
    return 0;
}