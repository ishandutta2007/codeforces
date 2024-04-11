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
int k;
int x[200000];
ll s[200001];
pair<ll, int> p[200000];

int main () {
    scanf ("%d%d", &n, &k);
    for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
    s[n] = 0;
    for (int i = n - 1; i >= 0; i--) s[i] = s[i + 1] + x[i];
    ll cur = 0;
    int pos = 0;
    for (int i = k - 1; i < n; i++) {
        ll tmp = s[i - k + 1] - s[i + 1];
        if (tmp > cur) {
            cur = tmp;
            pos = i - k + 1;
        }
        p[i] = mp (cur, pos);
    }
    cur = pos = 0;
    ll ans = 0;
    int a = 0, b = 0;
    for (int i = n - k; i >= k; i--) {
        ll tmp = s[i] - s[i + k];
        if (tmp >= cur) {
            cur = tmp;
            pos = i;
        }
        if (cur + p[i - 1].fi >= ans) {
            ans = cur + p[i - 1].fi;
            a = p[i - 1].se;
            b = pos;
        }
    }
    printf ("%d %d\n", a + 1, b + 1);
    return 0;
}