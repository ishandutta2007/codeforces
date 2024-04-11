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
typedef pair<ll, ll> pll;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

const int mod = 1000000000 + 7;

int n;
int x;
int a[100000];
multiset<pll> all;

int power (int a, ll b) {
    int c = 1;
    while (b) {
        if (b & 1) c = ((ll)c * a) % mod;
        a = ((ll)a * a) % mod;
        b /= 2;
    }
    re c;
}

int main () {
    scanf ("%d%d", &n, &x);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        scanf ("%d", &a[i]);
        sum += a[i];
    }
    for (int i = 0; i < n; i++) all.insert (mp (sum - a[i], 1));
    ll cur = 0;
    while (!all.empty ()) {
        ll tmp = all.begin ()->fi;
        ll cnt = 0;
        while (!all.empty () && all.begin ()->fi == tmp) {
            cnt += all.begin ()->se;
            all.erase (all.begin ());
        }
        cur = tmp;
        while (cnt % x == 0) {
            tmp++;
            cnt /= x;
        }
        if (tmp == cur) break;
        all.insert (mp (tmp, cnt));
    }
    printf ("%d\n", power (x, min (sum, cur)));
    return 0;
}