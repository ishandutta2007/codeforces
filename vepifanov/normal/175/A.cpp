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
string s;

ll cool (string s) {
    if (s == "0") re 0;
    if (s[0] == '0') re -1;
    ll x = 0;
    for (int i = 0; i < sz (s); i++) x = x * 10 + s[i] - '0';
    re x;
}

int main () {
    cin >> s;
    int n = sz (s);
    int ans = -1;
    for (int a = 1; a <= 10 && a < n; a++)
        for (int b = 1; b <= 10 && a + b < n; b++) {
            int c = n - a - b;
            if (c > 10) continue;
            ll x = cool (s.substr (0, a));
            ll y = cool (s.substr (a, b));
            ll z = cool (s.substr (a + b, c));
            if (x >= 0 && x <= 1000000 && y >= 0 && y <= 1000000 && z >= 0 && z <= 1000000) ans = max ((ll)ans, x + y + z);
        }
    printf ("%d\n", ans);
    return 0;
}