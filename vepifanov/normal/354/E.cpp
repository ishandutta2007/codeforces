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

const int l[3] = {0, 4, 7};

int n;
int m;
int was[20][6][60];
int ct;
ll z[6];
int y[20];

int go (int i, int j, int s, ll base) {
    if (j == 6) {
        if (s % 10 == y[i]) re go (i + 1, 0, s / 10, base * 10);
        re 0;
    }
    if (i == 19) {
        if (s == 0) {
            for (int j = 0; j < 6; j++) cout << z[j] << " ";
            cout << endl;
            re 1;
        }
        re 0;
    }
    if (was[i][j][s] == ct) re 0;
    was[i][j][s] = ct;
    for (int t = 0; t < 3; t++) {
        z[j] += base * l[t];
        if (go (i, j + 1, s + l[t], base)) re 1;
        z[j] -= base * l[t];
    }
    re 0;
}

int main () {
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        for (int i = 0; i < 19; i++) {
            y[i] = x % 10;
            x /= 10;
        }
        ct++;
        memset (z, 0, sizeof (z));
        if (!go (0, 0, 0, 1)) printf ("-1\n");
    }
    return 0;
}