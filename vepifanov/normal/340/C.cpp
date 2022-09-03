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

#define filename ""

const double pi = 2 * asin (1.0);

int n;
int m;
int x[200000];

ll gcd (ll a, ll b) {
    re a ? gcd (b % a, a) : b;
}

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
    sort (x, x + n);
    ll s1 = 0, s2 = 0;
    for (int i = 0; i < n; i++) s2 += x[i];
    ll ans = s2;
    for (int i = 0; i < n; i++) {
        s2 -= x[i];
        ans += (ll)x[i] * i - s1;
        ans += s2 - (ll)x[i] * (n - i - 1);
        s1 += x[i];
    }
    ll d = gcd (ans, n);
    cout << ans / d << " " << n / d << endl;
    return 0;
}