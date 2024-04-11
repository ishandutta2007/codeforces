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

int p[1001][61];
ll q[1001][61];
int a, b, w, x, c;

int main () {
    scanf ("%d%d%d%d%d", &a, &b, &w, &x, &c);
    for (int i = 0; i < w; i++)
        if (i >= x) {
            p[i][0] = i - x;
            q[i][0] = 0;
        } else {
            p[i][0] = w - (x - i);
            q[i][0] = 1;
        }
    for (int j = 0; j < 60; j++)
        for (int i = 0; i < w; i++) {
            p[i][j + 1] = p[p[i][j]][j];
            q[i][j + 1] = q[i][j] + q[p[i][j]][j];
        }
    int j = 60;
    ll ans = 0;
    while (c > a)
        if (j == 0 || c - ((ll)1 << j) > a - q[b][j]) {
            c -= ((ll)1 << j);
            a -= q[b][j];
            b = p[b][j];
            ans += ((ll)1 << j);
        } else j--;
    cout << ans << endl;
    return 0;
}