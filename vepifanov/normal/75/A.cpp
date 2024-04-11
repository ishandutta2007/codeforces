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

ll n, m;

ll get (ll x) {
    ll y = 0;
    while (x) { if (x % 10) y = y * 10 + x % 10; x /= 10; }
    ll z = 0;
    while (y) { z = z * 10 + y % 10; y /= 10; }
    re z;
}

int main() {
    cin >> n >> m;
    if (get (n + m) == get (n) + get (m)) printf ("YES\n"); else printf ("NO\n");
    return 0;
}