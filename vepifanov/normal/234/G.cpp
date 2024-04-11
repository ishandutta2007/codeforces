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

int main () {
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    scanf ("%d", &n);
    int ans = 1;
    m = 1;
    while (2 * m < n) {
        ans++;
        m *= 2;
    }
    printf ("%d\n", ans);
    for (int i = 0; i < ans; i++) {
        vi v;
        for (int j = 0; j < n; j++)
            if ((j / m) % 2 == 0)
                v.pb (j + 1);
        printf ("%d", sz (v));
        for (int j = 0; j < sz (v); j++)
            printf (" %d", v[j]);
        printf ("\n");
        m /= 2;
    }
    return 0;
}