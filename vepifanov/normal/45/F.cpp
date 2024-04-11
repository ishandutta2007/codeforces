#include <cstdio>
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

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < n; i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define y0 y3487465
#define y1 y8687969

typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) {
    re x > 0 ? x : -x;
}

const int res[5][3] = {{-1, 1, 1}, {-1, 5, 3}, {-1, 11, 5}, {-1, -1, 9}, {-1, -1, 11}};

int n;
int m;

int main() {
    scanf ("%d%d", &m, &n);
    int ans = -1;
    if (n < 4) {
        if (m < 6) ans = res[m - 1][n - 1];
    } else {
        int k = (n - 2) / 2;
        if ((n & 1) == 0 && m > 1) m--;
        ans = ((m - 1) / k) * 2 + 1;
        if (n & 1) {
            if (m > 4 * k + 3) ans = ((m - 4 * k - 4) / k) * 2 + 9; else
            if (m <= k + 1) ans = 1; else
            if (m <= 2 * k + 2) ans = 3; else
            if (m <= 3 * k + 2) ans = 5; else ans = 7;
        }
    }
    printf ("%d\n", ans);
    return 0;
}