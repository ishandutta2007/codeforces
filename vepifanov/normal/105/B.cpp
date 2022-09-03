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
int x;
int p[8], q[8];
double ans;

int go (int i, int j) {
    if (i == n) {
        double cur = 0;
        for (int i = 0; i < (1 << n); i++) {
            int sum = 0, cnt = 0;
            double prob = 1;
            for (int j = 0; j < n; j++)
                if ((i >> j) & 1) {
                    cnt++;
                    prob *= q[j] / 100.0;
                } else {
                    prob *= 1 - q[j] / 100.0;
                    sum += p[j];
                }   
            if (2 * cnt > n) cur += prob; else cur += prob * x / (x + sum);
        }
        ans = max (ans, cur);
        re 0;
    }
    for (int k = 0; k <= j && q[i] + 10 * k <= 100; k++) {
        q[i] += k * 10;
        go (i + 1, j - k);
        q[i] -= k * 10;
    }
    re 0;
}

int main () {
    scanf ("%d%d%d", &n, &m, &x);
    for (int i = 0; i < n; i++) scanf ("%d%d", &p[i], &q[i]);
    ans = 0;
    go (0, m);
    printf ("%.10f\n", ans);
    return 0;
}