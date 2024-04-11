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
#define prev PREV
                         
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
int x[200002];
int y[200002];
int sl[200002];
int sr[200002];
int ml[200002];
int mr[200002];

int main () {
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++) scanf ("%d%d", &x[i], &y[i]);      
    sl[0] = ml[0] = 0;
    for (int i = 1; i <= n; i++) {
        sl[i] = sl[i - 1] + x[i];
        ml[i] = max (ml[i - 1], y[i]);
    }
    sr[n + 1] = mr[n + 1] = 0;
    for (int i = n; i >= 1; i--) {
        sr[i] = sr[i + 1] + x[i];
        mr[i] = max (mr[i + 1], y[i]);
    }
    for (int i = 1; i <= n; i++)
        printf ("%d ", max (ml[i - 1], mr[i + 1]) * (sl[i - 1] + sr[i + 1]));
    printf ("\n");
    return 0;
}