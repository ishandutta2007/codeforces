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
int m;
int mul;
ll h[1000001];
ll p[1000001];
vector<ll> v, w;

int prime (int x) {
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            re 0;
    re 1;
}

int main () {
    mul = 10000000;
    while (!prime (mul)) mul++;
    p[0] = 1;
    for (int i = 1; i <= 1000000; i++) p[i] = p[i - 1] * mul;
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf ("%d%d", &a, &b); a--; b--;
        h[a] += p[b];
        h[b] += p[a];
    }
    for (int i = 0; i < n; i++) {
        v.pb (h[i]);
        w.pb (h[i] + p[i]);
    }
    sort (all (v));
    sort (all (w));
    ll ans = 0;
    int cur;
    cur = 0;
    for (int i = 0; i < n; i++) {
        if (i > 0 && v[i - 1] != v[i]) cur = 0;
        cur++;
        ans += cur - 1;
    }
    cur = 0;
    for (int i = 0; i < n; i++) {
        if (i > 0 && w[i - 1] != w[i]) cur = 0;
        cur++;
        ans += cur - 1;
    }
    cout << ans << endl;
    return 0;
}