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
ll t1, t2, x1, x2, t0;

int main () {
    cin >> t1 >> t2 >> x1 >> x2 >> t0;
    if (t1 == t2) { cout << x1 << " " << x2 << endl; re 0; }
    ll ap = 1e9;
    ll aq = 1;
    ll y2 = x2, ay1 = 0, ay2 = 0;
    for (ll y1 = 0; y1 <= x1; y1++) {
        if (y1 == 1) y2 = 0;
        while (y2 <= x2 && y1 * t1 + y2 * t2 < t0 * (y1 + y2)) y2++;
        if (y2 > x2) break;
        if ((y1 * t1 + y2 * t2) * aq <= ap * (y1 + y2)) {
            ap = y1 * t1 + y2 * t2;
            aq = y1 + y2;
            ay1 = y1;
            ay2 = y2;
        }
    }
    cout << ay1 << " " << ay2 << " " << endl;
    return 0;
}