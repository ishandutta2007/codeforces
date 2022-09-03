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
int x[200];

int main () {
    scanf ("%d", &n);
    int y = 0, ok = 0;
    for (int i = 0; i < 2 * n - 1; i++) {
        scanf ("%d", &x[i]);
        if (x[i] < 0) y ^= 1;
        if (x[i] == 0) ok = 1;
        x[i] = abs (x[i]);
    }
    sort (x, x + 2 * n - 1);
    if (n % 2 == 1 || ok) y = 0;
    int ans = 0;
    for (int i = 0; i < 2 * n - 1; i++)
        if (i < y)
            ans -= x[i];
        else
            ans += x[i];    
    printf ("%d\n", ans);
    return 0;
}