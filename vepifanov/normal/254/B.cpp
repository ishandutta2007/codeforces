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

const int mm[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int n;
int m;
int d[100], p[100], t[100];

int main () {
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        int m;
        scanf ("%d%d%d%d", &m, &d[i], &p[i], &t[i]);
        for (int j = 0; j + 1 < m; j++) d[i] += mm[j];
    }
    int ans = 0;
    for (int i = -100; i <= 365; i++) {
        int cur = 0;
        for (int j = 0; j < n; j++)
            if (i >= d[j] - t[j] && i < d[j])
                cur += p[j];
        ans = max (ans, cur);
    }
    printf ("%d\n", ans);
    return 0;
}