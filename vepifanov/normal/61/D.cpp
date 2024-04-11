#include <cstdio>
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

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < n; i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define y0 y3487465
#define y1 y8687969

typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) {
    re x > 0 ? x : -x;
}

int n;
int m;
int ans;
vii v[100000];

int go (int x, int l, int p) {
    ans = max (ans, l);
    for (int i = 0; i < sz (v[x]); i++)
        if (v[x][i].fi != p)
            go (v[x][i].fi, l + v[x][i].se, x);
    re 0;
}

int main() {
    scanf ("%d", &n);   
    ll all = 0;
    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        scanf ("%d%d%d", &a, &b, &c); a--; b--;
        v[a].pb (mp (b, c));
        v[b].pb (mp (a, c));
        all += 2 * c;
    }
    ans = 0;
    go (0, 0, -1);
    cout << all - ans << endl;
    return 0;
}