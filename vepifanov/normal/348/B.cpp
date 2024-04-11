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
typedef pair<pair<ll, ll>, pair<ll, ll> > llll;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

const ll inf = 1e18;

int n;
int m;
int s[100000];
vi v[100000];

ll gcd (ll a, ll b) {
    re a ? gcd (b % a, a) : b;
}

llll go (int x, int p) {
    if (sz (v[x]) - int (p != -1) == 0) re mp (mp (s[x], 1), mp (1, 0));
    ll sum = 0, cnt = 0, cur = 1e18, rem = 0, num = 0, dec = 1;
    for (int i = 0; i < sz (v[x]); i++) {
        int y = v[x][i];
        if (y == p) continue;
        llll tmp = go (y, x);
        ll d = gcd (dec, tmp.fi.se);
        tmp.fi.se /= d;
        if (dec <= inf / tmp.fi.se) dec *= tmp.fi.se; else dec = inf;
        cur = (min (cur, tmp.fi.fi) / dec) * dec;
        cnt += tmp.se.fi;
        sum += tmp.se.se;
        rem += tmp.fi.fi;
        num++;
    }
    if (dec <= inf / num) dec *= num; else dec = inf;
    re mp (mp (cur * num, dec), mp (cnt, sum + rem - cur * num));
}
                      
int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) scanf ("%d", &s[i]);
    for (int i = 0; i + 1 < n; i++) {
        int a, b;
        scanf ("%d%d", &a, &b); a--; b--;
        v[a].pb (b);
        v[b].pb (a);
    }
    cout << go (0, -1).se.se << endl;
    return 0;
}