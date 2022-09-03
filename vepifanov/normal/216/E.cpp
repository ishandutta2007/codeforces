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
int m, k, b;
int x[100000];
map<int, int> all;

int main () {
    scanf ("%d%d%d", &k, &b, &n);
    int bb = b % (k - 1);
    for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
    int cur = 0;
    ll ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        all[cur]++;
        cur = (cur + x[i]) % (k - 1);
        int tmp = (cur - bb + k - 1) % (k - 1);
        ans += all[tmp];
    }
    ll ans0 = 0;
    cur = 0;
    for (int i = 0; i < n; i++) {
        if (x[i] == 0) cur++; else cur = 0;
        ans0 += cur;
    }
    if (b == 0) ans = ans0; else
    if (bb == 0) ans -= ans0;
    cout << ans << endl;
    return 0;
}