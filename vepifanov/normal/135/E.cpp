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

const int mod = 1000000000 + 7;

int n;
int m, w;

int power (int a, int b) {
    int c = 1;
    while (b) {
        if (b & 1) c = ((ll)c * a) % mod;
        b /= 2;
        a = ((ll)a * a) % mod;
    }
    re c;
}

int f[1000001], rf[1000001];

int main () {
    scanf ("%d%d", &n, &w);
    f[0] = rf[0] = 1;
    for (int i = 1; i <= n; i++) {
        f[i] = ((ll)f[i - 1] * i) % mod;
        rf[i] = power (f[i], mod - 2);
    }
    int ans = 0, cur = 1;
    for (int i = 1; i <= n; i++) {
        cur = ((ll)cur * (n - i + 1)) % mod;
        if (i + 2 <= w) {
            int all = ((ll)cur * n) % mod;
            all = ((ll)all * all) % mod;
            int tmp = f[n];
            if (n - i - 1 >= 0) tmp = ((ll)tmp * rf[n - i - 1]) % mod; else tmp = 0;
            tmp = ((ll)tmp * tmp) % mod;
            tmp = (all - tmp + mod) % mod;
            tmp = ((ll)tmp * power (n, w - i - 2)) % mod;
            ans = ((ll)ans + tmp) % mod;
        } else
        if (i + 1 == w) {
            int all = ((ll)cur * cur) % mod;
            all = ((ll)all * n) % mod;
            int tmp = ((ll)f[n - 1]) % mod;
            if (n - i - 1 >= 0) tmp = ((ll)tmp * rf[n - i - 1]) % mod; else tmp = 0;
            tmp = ((ll)tmp * tmp) % mod;
            tmp = ((ll)tmp * n) % mod;
            ans = ((ll)ans + all - tmp + mod) % mod;
        } else {
            int k = i - w;
            int all = ((ll)f[n] * rf[n - i]) % mod;
            all = ((ll)all * f[n - k]) % mod;
            all = ((ll)all * rf[n - i]) % mod;
            int tmp = ((ll)f[n] * rf[n - i]) % mod;
            tmp = ((ll)tmp * (n - i)) % mod;
            tmp = ((ll)tmp * f[n - (k + 2)]) % mod;
            if (n - i - 1 >= 0) tmp = ((ll)tmp * rf[n - i - 1]) % mod; else tmp = 0;
            ans = ((ll)ans + all - tmp + mod) % mod;
        }
    }
    printf ("%d\n", ans);
    return 0;
}