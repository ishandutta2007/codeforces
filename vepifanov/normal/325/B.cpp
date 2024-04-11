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

const ll MAX = 2e18;
const ll MAX2 = 2e9;

ll n;
int m;
vector<ll> v;

ll calc (ll x, int k) {
    ll tmp = ((ll)1 << k) - 1;
    if (tmp > 0 && x >= MAX / tmp) re MAX;
    re x * (x - 1) / 2 + x * tmp;
}

int main () {
    cin >> n;
    for (int k = 0; calc (1, k) <= n; k++) {
        ll l = 1, r = 2e9;
        while (r - l > 1) {
            ll s = (l + r) / 2;
            if (calc (s, k) > n) r = s; else l = s;
        }
        if (l % 2 == 1 && calc (l, k) == n) v.pb (l << k);
    }
    if (v.empty ()) v.pb (-1);
    sort (all (v));
    for (int i = 0; i < sz (v); i++) cout << v[i] << endl;
    return 0;
}