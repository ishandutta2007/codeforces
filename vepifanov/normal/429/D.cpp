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

const int N = 50;
const int M = 20;

int n;
int m;
ll ans;
vii v, w;
int x[100000];

ll dist (ii a, ii b) {
    re sqr ((ll)a.fi - b.fi) + sqr ((ll)a.se - b.se);
}

int go (vii v, vii w) {
    if (sz (v) < N) {
        for (int i = 0; i < sz (v); i++)
            for (int j = i + 1; j < sz (v); j++)
                ans = min (ans, dist (v[i], v[j]));
        re 0;
    }
    int mid = (v[0].fi + v[sz (v) - 1].fi) / 2;
    vii v1, v2, w1, w2, w3;
    for (int i = 0; i < sz (v); i++) {
        if (v[i].fi <= mid)
            v1.pb (v[i]);
        else
            v2.pb (v[i]);   
        if (w[i].se <= mid)
            w1.pb (w[i]);
        else
            w2.pb (w[i]);   
    }   
    go (v1, w1);
    go (v2, w2);
    for (int i = 0; i < sz (w); i++)
        if (sqr (w[i].se - mid) < ans)
            w3.pb (w[i]);           
    for (int i = 0; i < sz (w3); i++)
        for (int j = i + 1; j < i + M && j < sz (w3); j++)
            ans = min (ans, dist (w3[i], w3[j]));
    re 0;
}

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
    int cur = 0;
    for (int i = 0; i < n; i++) {
        cur += x[i];
        v.pb (mp (i, cur));
        w.pb (mp (cur, i));
    }
    sort (all (v));
    sort (all (w));
    ans = 8e18;
    go (v, w);
    cout << ans << endl;
    return 0;  
}