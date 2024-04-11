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
int m;
int f[1000001];
int rf[1000001];
int a, b;

int power (int a, int b) {
    int c = 1;
    while (b) {
        if (b & 1) c = ((ll)c * a) % mod;
        a = ((ll)a * a) % mod;
        b /= 2;
    }
    re c;
}

int cnk (int n, int k) {
    re (((ll)f[n] * rf[k]) % mod * rf[n - k]) % mod;
}

int cool (int x) {
    while (x) {
        if (x % 10 != a && x % 10 != b) re 0;
        x /= 10;
    }
    re 1;
}

int main () {
    f[0] = rf[0] = 1;
    for (int i = 1; i <= 1000000; i++) {
        f[i] = ((ll)f[i - 1] * i) % mod;
        rf[i] = power (f[i], mod - 2);
    }
    scanf ("%d%d%d", &a, &b, &n);
    int ans = 0;
    for (int i = 0; i <= n; i++)
        if (cool (a * i + b * (n - i)))
            ans = (ans + cnk (n, i)) % mod;
    printf ("%d\n", ans);
    return 0;
}