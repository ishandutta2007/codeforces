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

const int MAX = 1000000000;

ll n, m;
vector<ll> v;

int go (ll x) {
    v.pb (x);
    if (x <= MAX) {
        go (x * 10 + 4);
        go (x * 10 + 7);
    }
    re 0;
}

int main () {
    cin >> n >> m;
    go (0);
    sort (all (v));
    ll ans = 0;
    for (int i = 1; i < sz (v); i++)
        ans += v[i] * max ((ll)0, (min (v[i], m) - max (v[i - 1] + 1, n) + 1));
    cout << ans << endl;
    return 0;
}