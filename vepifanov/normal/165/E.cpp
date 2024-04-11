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

const int full = (1 << 22) - 1;

int n;
int m;

int was[full + 1];
int res[full + 1];
int x[1000000];

int go (int x) {
    if (was[x]) re res[x];
    was[x] = 1;
    res[x] = -1;
    for (int i = 0; i < 22; i++)
        if ((x >> i) & 1) {
            int tmp = go (x - (1 << i));
            if (tmp != -1) {
                res[x] = tmp;
                break;
            }
        }
    re res[x];
}

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf ("%d", &x[i]);
        was[x[i]] = res[x[i]] = x[i];
    }
    for (int i = 0; i < n; i++) printf ("%d ", go (full - x[i]));
    printf ("\n");
    return 0;
}