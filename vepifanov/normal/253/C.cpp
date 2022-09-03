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
int a[100];
int r1, c1, r2, c2;

int main () {
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) scanf ("%d", &a[i]);
    scanf ("%d%d%d%d", &r1, &c1, &r2, &c2); r1--; r2--;
    int ans = 1e9;
    for (int k = 0; k < n; k++) {
        int cur = 0;
        int r1 = ::r1, c1 = ::c1;
        while (r1 != k) {
            if (r1 > k) r1--; else r1++;
            c1 = min (c1, a[r1] + 1);
            cur++;
        }
        while (r1 != r2) {
            if (r1 > r2) r1--; else r1++;
            c1 = min (c1, a[r1] + 1);
            cur++;
        }
        cur += abs (c1 - c2);
        ans = min (ans, cur);
    }   
    printf ("%d\n", ans);
    return 0;
}