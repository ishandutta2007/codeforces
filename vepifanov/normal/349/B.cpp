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
int x[10];

int main () {
    scanf ("%d", &n);
    int y = 1e9;
    for (int i = 1; i < 10; i++) {
        scanf ("%d", &x[i]);
        y = min (y, x[i]);
    }   
    int m = n / y;
    for (int i = 0; i < m; i++)
        for (int j = 9; j > 0; j--)
            if (x[j] <= n && (n - x[j]) >= y * (m - i - 1)) {
                n -= x[j];
                printf ("%d", j);
                break;
            }
    if (m == 0) printf ("-1");
    printf ("\n");
    return 0;
}