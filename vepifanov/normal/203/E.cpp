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
int m, d, s;

ll cs[100001];
vi v, w, u;

int main () {
    scanf ("%d%d%d", &n, &d, &s);
    int can = 0, cnt = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
        int c, f, l;
        scanf ("%d%d%d", &c, &f, &l);
        if (c == 0) {
            cnt2++;
            if (l >= d) v.pb (f);
        } else {
            cnt++;
            if (l >= d) w.pb (f);
            can = min (can + c - 1, 2 * n);
        }   
        if (l >= d) u.pb (f);
    }
    sort (all (v));
    sort (all (w));
    sort (all (u));
    int ans = 0;
    int res = 0;
    int sum = 0;
    for (int i = 0; i < sz (u); i++) {
        sum += u[i];
        if (sum > s) break;
        ans = i + 1;
        res = sum;
    }
    cs[0] = 0;
    for (int i = 0; i < sz (v); i++) cs[i + 1] = cs[i] + v[i];
    sum = 0;
    for (int i = 1; i <= sz (w); i++) {
        sum += w[i - 1];
        if (sum > s) break;
        int l = 0, r = min (sz (v), max (0, cnt2 - (can + i)));
        while (r - l > 1) {
            int s = (l + r) / 2;
            if (cs[s] <= ::s - sum) l = s; else r = s;
        }
        if (cs[r] > ::s - sum) r = l;
        int cans = cnt + r + min (cnt2, can + i);
        int cres = sum + cs[r];
        if (cans > ans || cans == ans && cres < res) {
            ans = cans;
            res = cres;
        }
    }
    printf ("%d %d\n", ans, res);
    return 0;
}