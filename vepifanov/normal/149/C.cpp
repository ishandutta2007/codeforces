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

ii x[100000];
int s[100001];

int main () {
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> x[i].fi;
        x[i].se = i;
        sum += x[i].fi;
    }   
    int m = n / 2, M = (n + 1) / 2;
    sort (x, x + n);
    s[n] = 0;
    for (int i = n - 1; i >= 0; i--) s[i] = s[i + 1] + x[i].fi;
    int res = 2e9, posa = 0, posb = 0;
    for (int i = 0; i < n; i++) {
        if (i + m <= n) {
            int cur = s[i] - s[i + m];
            if (abs (2 * cur - sum) < res) {
                res = abs (2 * cur - sum);
                posa = i;
                posb = i + m; 
            }
        }
        if (i + M <= n) {
            int cur = s[i] - s[i + M];
            if (abs (2 * cur - sum) < res) {
                res = abs (2 * cur - sum);
                posa = i;
                posb = i + M; 
            }
        }
    }   
    printf ("%d\n", posb - posa);
    for (int i = posa; i < posb; i++) printf ("%d ", x[i].se + 1);
    printf ("\n%d\n", n - (posb - posa));
    for (int i = 0; i < posa; i++) printf ("%d ", x[i].se + 1);
    for (int i = posb; i < n; i++) printf ("%d ", x[i].se + 1);
    printf ("\n");
    return 0;
}