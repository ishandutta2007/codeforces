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

int was[1000000];
vi v[1000000];
int cnt[1000000];
multiset<int> all;

int go (int x) {    
    was[x] = 1;
    int tmp = cnt[x] & 1;
    for (int i = 0; i < sz (v[x]); i++)
        if (!was[v[x][i]])
            tmp += go (v[x][i]);
    re tmp;
}

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf ("%d%d", &a, &b); a--; b--;
        v[a].pb (b);
        v[b].pb (a);
        cnt[a]++;
        cnt[b]++;
    }
    for (int i = 0; i < n; i++)
        if (!was[i] && (i == 0 || sz (v[i]) > 0))
            all.insert (-go (i));
    int ans = 0;
    while (sz (all) > 1) {
        int a = -*all.begin ();
        all.erase (all.begin ());
        int b = -*all.begin ();
        all.erase (all.begin ());
        if (b == 0) {
            all.insert (-a);
            all.insert (-b);
            break;
        }
        ans++;
        all.insert (-(a + b - 2));
    }
    int x = -*all.begin ();
    int y = sz (all);
    if (y > 1) {
        if (x > 0) x -= 2;
        ans += x / 2 + y;
    } else {
        ans += x / 2;
    }
    printf ("%d\n", ans);
    return 0;
}