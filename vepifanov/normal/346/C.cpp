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

const int N = 10;

int n;
int m;

int x[100000];
int now[100000];
vi v[1000001];
int cnt[1000001];
int res[1000001];
int a, b;

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
    sort (x, x + n);
    n = unique (x, x + n) - x;
    scanf ("%d%d", &b, &a);
    for (int i = 0; i <= b - a; i++) v[i].reserve (N);
    for (int i = 0; i < n; i++) {
        int cx = x[i];
        int y = (a / cx - int (a % cx == 0)) * cx;
        if (y < a) y += x[i];
        if (y <= b) v[y - a].pb (x[i]);
    }
    cerr << clock () << endl;
    int cur = 0;
    for (int i = 0; i <= b - a; i++) {
        for (int j = 0; j < sz (v[i]); j++) {
            int k = v[i][j];
            if (i - k >= 0) cnt[i - k]--;
            if (i + k <= b - a) v[i + k].pb (k);
            cnt[i]++;
        }
        if (i == 0) res[i] = 0; else {
            while (cur < i && !cnt[cur]) cur++;
            res[i] = res[i - 1] + 1;
            if (cur < i) res[i] = res[cur] + 1;
        }
    }
    printf ("%d\n", res[b - a]);
    return 0;
}