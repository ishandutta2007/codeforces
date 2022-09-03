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

const string name[2] = {"BitAryo", "BitLGM"};

int n;
int m;

int was1[301];
int was2[301][301];
int res1[301];
int res2[301][301];
int x[3];

int go (int a) {
    if (a == 0) re 0;
    if (was1[a]) re res1[a];
    was1[a] = 1;
    int cur = 0;
    for (int t = a; t >= 1 && !cur; t--)
        if (!go (a - t))
            cur = 1;
    re res1[a] = cur;
}

int go (int a, int b) {
    if (a > b) swap (a, b);
    if (b == 0) re 0;
    if (was2[a][b]) re res2[a][b];
    was2[a][b] = 1;
    int cur = 0;
    for (int t = b; t >= 1 && !cur; t--) {
        if (!go (a, b - t))
            cur = 1;
        if (t <= a) {
            if (!go (a - t, b - t))
                cur = 1;
            if (!go (a - t, b))
                cur = 1;
        }
    }
    re res2[a][b] = cur;
}

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
    int ans = 0;
    if (n == 1) ans = go (x[0]);
    if (n == 2) ans = go (x[0], x[1]);
    if (n == 3) ans = int ((x[0] ^ x[1] ^ x[2]) != 0);
    printf ("%s\n", name[ans].c_str ());
    return 0;
}