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
int x[1000];
int y[1000];
int r[1000];

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
    for (int i = 0; i + 1 < n; i++) {
        y[i] = x[i] + x[i + 1];
        r[i] = abs (x[i + 1] - x[i]);
    }
    for (int i = 0; i + 1 < n; i++)
        for (int j = i + 1; j + 1 < n; j++)
            if (abs (y[i] - y[j]) < r[i] + r[j] && abs (y[i] - y[j]) > abs (r[i] - r[j])) {
                printf ("yes\n");
                re 0;
            }
    printf ("no\n");
    return 0;
}