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
int k;
int x[100000];
int l[100000];
int r[100000];
int w[100001];
ll u[100001];
int d[100000];

int main () {
    scanf ("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
    for (int i = 0; i < m; i++) scanf ("%d%d%d", &l[i], &r[i], &d[i]);
    for (int i = 0; i < k; i++) {
        int x, y;
        scanf ("%d%d", &x, &y);
        w[x - 1]++;
        w[y]--;
    }
    int cur = 0;
    for (int i = 0; i < m; i++) {
        cur += w[i];
        u[l[i] - 1] += (ll)cur * d[i];
        u[r[i]] -= (ll)cur * d[i];
    }
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += u[i];
        printf ("%I64d ", sum + x[i]);
    }
    printf ("\n");
    return 0;
}