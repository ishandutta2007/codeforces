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
int p[200001];
int x[200000];
int y[200000];

int get (int x) {
    if (p[x] != x) p[x] = get (p[x]);
    re p[x];
}

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
    for (int i = 0; i <= n; i++) p[i] = i;
    scanf ("%d", &m);
    for (int i = 0; i < m; i++) {
        int t, a, b;
        scanf ("%d", &t);
        if (t == 2) {
            scanf ("%d", &a); a--;
            printf ("%d\n", y[a]);
        } else {
            scanf ("%d%d", &a, &b); a--;
            while (b > 0) {
                a = get (a);
                if (a == n) break;
                int tmp = min (x[a] - y[a], b);
                y[a] += tmp;
                b -= tmp;
                if (y[a] == x[a]) p[a] = a + 1;
            }
        }   
    }
    return 0;
}