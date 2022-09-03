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

char h[100100];
string s;
string t[100000];
int d[100000];
int x[10];
int y[10];

int main () {
    gets (h);
    s = string (h);
    scanf (" %d", &n);
    for (int i = 0; i < 10; i++) {
        x[i] = 10;
        y[i] = i;
    }
    gets (h);
    for (int i = 0; i < n; i++) {
        gets (h);
        d[i] = h[0] - '0';
        t[i] = string (h + 3);
    }
    for (int i = n - 1; i >= 0; i--) {
        int cx = 1, cy = 0;
        for (int j = 0; j < sz (t[i]); j++) {
            int c = t[i][j] - '0';
            cx = ((ll)cx * x[c]) % mod;
            cy = ((ll)cy * x[c] + y[c]) % mod;
        }
        x[d[i]] = cx;
        y[d[i]] = cy;
    }
    int cur = 0;
    for (int i = 0; i < sz (s); i++) {
        int c = s[i] - '0';
        cur = ((ll)cur * x[c] + y[c]) % mod;
    }
    printf ("%d\n", cur);
    return 0;
}