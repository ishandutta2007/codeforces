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
vi v[200000];

int go (int x, int p) {
    if (v[x].empty ()) re 0;
    if (p == 0) {
        int y = 1e9;
        for (int i = 0; i < sz (v[x]); i++)
            y = min (y, go (v[x][i], 1));
        re y;
    } else {
        int y = sz (v[x]) - 1;
        for (int i = 0; i < sz (v[x]); i++)
            y += go (v[x][i], 0);
        re y;
    }
}

int main () {
    scanf ("%d", &n);
    for (int i = 1; i < n; i++) {
        int a, b;
        scanf ("%d%d", &a, &b); a--; b--;
        v[a].pb (b);
    }
    m = 0;
    for (int i = 0; i < n; i++)
        m += int (v[i].empty ());
    cout << m - go (0, 0) << " " << go (0, 1) + 1 << endl;
    return 0;
}