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

const int mod = 1000*1000*1000 + 7;
const int N = 1000*1000;

int n;
int m;
int was[N][4][4];
int res[N][4][4];
string s;
int x[N];

int cool (int i, int a, int b, int c) {
    re int (i == 0 || b == 3 || b == int (a == 3) + int (c == 3));
}

int go (int i, int a, int b) {
    if (i == n) re cool (i, a, b, 0);
    if (was[i][a][b]) re res[i][a][b];
    was[i][a][b] = 1;
    unsigned int cur = 0;
    for (int c = 0; c < 4; c++)
        if ((x[i] == 4 || c == x[i]) && cool (i, a, b, c))
            cur += go (i + 1, b, c);
    re res[i][a][b] = cur % mod;
}

int main () {
    cin >> s;
    n = sz (s);
    for (int i = 0; i < n; i++) x[i] = s[i] == '?' ? 4 : (s[i] == '*' ? 3 : s[i] - '0');
    printf ("%d\n", go (0, 0, 0));
    return 0;
}