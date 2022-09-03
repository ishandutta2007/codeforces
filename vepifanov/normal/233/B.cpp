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

ll n;

int calc (ll x) {
    int y = 0;
    while (x) {
        y += x % 10;
        x /= 10;
    }
    re y;
}

int main () {
    cin >> n;
    ll ans = -1;
    for (int t = 1; t <= 200; t++) {
        ll l = 0, r = 1e9 + 1;
        while (r - l > 1) {
            ll s = (l + r) / 2;
            if (s * (s + t) <= n) l = s; else r = s;
        }
        if (l * (l + t) == n && calc (l) == t && (ans == -1 || ans > l)) ans = l;
    }
    cout << ans << endl;
    return 0;
}