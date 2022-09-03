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
int p[1000], q[1000];

pair<ll, int> get (int *x, int n) {
    ll res = 1e18;
    int pos;
    for (int i = 0; i <= n; i++) {
        ll cur = 0;
        for (int j = 0; j < n; j++)
            cur += sqr ((ll)(4 * i - (4 * j + 2))) * x[j];
        if (cur < res) {
            res = cur;
            pos = i;
        }
    }
    re mp (res, pos);
}

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            int g;
            scanf ("%d", &g);
            p[i] += g;
            q[j] += g;
        }   
    pair<ll, int> a = get (p, n), b = get (q, m);
    printf ("%I64d\n%d %d\n", a.fi + b.fi, a.se, b.se);
    return 0;
}