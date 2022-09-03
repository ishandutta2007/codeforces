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

const ll MAX = 1e18;

int n;
int m, ct;
ll x[100], y[100];
int was[100][10][10];
ll res[100][10][10];
int q[100];

int go (ll x, int i) {
    if (x < 0) re 0;
    if (x == 0) {
        for (int j = 0; j <= i; j++) q[j] = 0;
        re 1;
    }   
    if (i == -1) re 0;
    if (y[i] < x) re 0;
    if (go (x - ::x[i], i - 1)) {
        q[i] = 1;
        re 1;
    }   
    q[i] = 0;
    re go (x, i - 1);
}

int cnt;

ll go2 (int i, int j, int k) {
    if (i == 0) re int (j == 0 && k == 0);
    if (j + k > i || j + q[i - 1] > 2 || j < 0 || k < 0) re 0;
    if (was[i][j][k] == ct) re res[i][j][k];
    was[i][j][k] = ct;
    ll cur = go2 (i - 1, k + j, j);
    if (q[i - 1] == 0) {
        cur += go2 (i - 1, k + j - 1, j - 1);
    } else {
        cur += go2 (i - 1, k + j + 1, j + 1);
    }
    re res[i][j][k] = cur;
}

int main () {
    x[0] = 1;
    x[1] = 2;
    y[0] = 1;
    y[1] = 3;
    int r = 2;
    while (true) {
        x[r] = x[r - 1] + x[r - 2];
        y[r] = y[r - 1] + x[r];
        r++;
        if (x[r - 1] >= MAX) break;
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        if (!go (x, r - 1)) cout << "0\n"; else {
            ct++;
            cout << go2 (r, 0, 0) << "\n";
        }
    }
    return 0;
}