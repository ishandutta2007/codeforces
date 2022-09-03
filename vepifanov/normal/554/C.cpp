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

const int mod = 1000*1000*1000+7;

int n;
int m;
int cnk[1001][1001];
int x[1000];
int y[1000];

int main () {
    for (int i = 0; i <= 1000; i++)
        for (int j = 0; j <= i; j++)
            if (i == 0 || j % i == 0)
                cnk[i][j] = 1;
            else
                cnk[i][j] = (cnk[i - 1][j] + cnk[i - 1][j - 1]) % mod;
    scanf ("%d", &n);
    int ans = 1, cur = 0;
    for (int i = 0; i < n; i++) {
        scanf ("%d", &x[i]);
        cur += x[i];
        y[i] = cur;
    }
    for (int i = n - 1; i >= 0; i--) ans = ((ll)ans * cnk[y[i] - 1][x[i] - 1]) % mod;
    cout << ans << endl;
    return 0;
}