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

int main() {
    scanf ("%d", &n);   
    ll ans = 0;
    for (int i = 0; i <= n; i++)
        if (i & 1) {
            int l = 0, r = 1e7;
            while (r - l > 1) {
                int s = (l + r) / 2;
                if (max ((ll)(3 * i + 2) * (3 * i + 2) + (ll)12 * s * (s - 1) + 3, (ll)(3 * i + 1) * (3 * i + 1) + (ll)12 * s * s) <= (ll)4 * n * n) l = s; else r = s;
            }
            ans += 2 * l * (1 + int (i > 0));
        } else {
            int l = -1, r = 1e7;
            while (r - l > 1) {
                int s = (l + r) / 2;
                if (max ((ll)(3 * i + 2) * (3 * i + 2) + (ll)12 * s * s, (ll)12 * s * (s + 1) + 3 + (ll)(3 * i + 1) * (3 * i + 1)) <= (ll)4 * n * n) l = s; else r = s;
            }
            if (l >= 0) ans += (2 * l + 1) * (1 + int (i > 0));
        }   
    cout << ans << endl;
    return 0;
}