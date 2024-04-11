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
#define prev PREV
                         
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
set<ii> all;

int gcd (int a, int b) { re a ? gcd (b % a, a) : b; }

int main () {
    int x0, y0;
    scanf ("%d%d%d", &n, &x0, &y0);
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf ("%d%d", &x, &y);
        x -= x0;
        y -= y0;
        int d = gcd (x, y);
        x /= d;
        y /= d;
        if (x < 0 || (x == 0 && y < 0)) {
            x = -x;
            y = -y;
        }
        all.insert (mp (x, y));
    }
    cout << sz (all) << endl;
    return 0;
}