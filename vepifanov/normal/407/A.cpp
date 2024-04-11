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
int a, b;
vii v, w;

vii calc (int a) {
    vii v;
    for (int i = 1, j = a; i < a; i++) {
        while (i * i + j * j > a * a) j--;
        if (i * i + j * j == a * a) {
            v.pb (mp (i, j));
            v.pb (mp (-i, j));
            v.pb (mp (i, -j));
            v.pb (mp (-i, -j));
        }   
    }       
    re v;
}

int main () {
    cin >> a >> b;
    v = calc (a);
    w = calc (b);
    for (int i = 0; i < sz (v); i++)
        for (int j = 0; j < sz (w); j++) {
            int x1 = v[i].fi, y1 = v[i].se;
            int x2 = w[j].fi, y2 = w[j].se;
            if (a * a + b * b == sqr (x2 - x1) + sqr (y2 - y1) && x1 != x2 && y1 != y2) {
                printf ("YES\n0 0\n%d %d\n%d %d\n", x1, y1, x2, y2);
                re 0;
            }
        }
    printf ("NO\n");
    return 0;
}