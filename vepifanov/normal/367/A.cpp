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
int cx[100001];
int cy[100001];
int cz[100001];
string s;

int main () {
    cin >> s;
    m = sz (s);
    cx[m] = cy[m] = cz[m] = 0;
    for (int i = m - 1; i >= 0; i--) {
        cx[i] = cx[i + 1] + int (s[i] == 'x');
        cy[i] = cy[i + 1] + int (s[i] == 'y');
        cz[i] = cz[i + 1] + int (s[i] == 'z');
    }
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf ("%d%d", &a, &b);
        int c = b - a + 1;
        int x = cx[a - 1] - cx[b];
        int y = cy[a - 1] - cy[b];
        int z = cz[a - 1] - cz[b];
        int ok = int (c <= 2);
        if (z == (c + 2) / 3 && y == (c + 1) / 3 && x == c / 3) ok = 1;
        if (x == (c + 2) / 3 && z == (c + 1) / 3 && y == c / 3) ok = 1;
        if (y == (c + 2) / 3 && x == (c + 1) / 3 && z == c / 3) ok = 1;
        printf ("%s\n", ok ? "YES" : "NO");
    }
    return 0;
}