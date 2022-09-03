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
double a, d;

int main () {
    cin >> a >> d >> n;
    int t = 0;
    double cur = 0;
    for (int i = 1; i <= n; i++) {
        cur += d;
        int k = cur / a;
        cur -= k * a;
        t = (t + k) % 4;
        if (t == 0) printf ("%.10f %.10f\n", cur, 0.0); else
        if (t == 1) printf ("%.10f %.10f\n", a, cur); else
        if (t == 2) printf ("%.10f %.10f\n", a - cur, a); else printf ("%.10f %.10f\n", 0.0, a - cur);
    }
    return 0;
}