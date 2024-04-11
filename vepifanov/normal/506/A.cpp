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
#include <unordered_map>

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

const int N = 30000;
const int M = 300;

int n;
int m;
int res[N + 1][2 * M + 1];
int cnt[N + 1];

int go (int x, int d) {
    if (x > N) re 0;
    if (res[x][d - m + M] != -1) re res[x][d - m + M];
    int cur = 0;
    for (int t = max (1, d - 1); t <= d + 1; t++)
        cur = max (cur, go (x + t, t));
    re res[x][d - m + M] = cur + cnt[x];
}

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        int x;
        scanf ("%d", &x);
        cnt[x]++;
    }
    memset (res, -1, sizeof (res));
    cout << go (m, m) << endl;
    return 0;
}