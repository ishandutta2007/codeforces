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

const int MAX = 10000000;

int n;
int m;
int x[1000000];
int f[MAX + 1];
int w[MAX + 1];
ll cnt[MAX + 1];
int q[MAX];
int r = 0;

ll calc (ll x, ll y) {
    ll z = 0;
    while (x) {
        x /= y;
        z += x;
    }
    re z;
}

int good (ll h) {
    for (int i = 0; i < r; i++)
        if (calc (h, q[i]) < cnt[q[i]])
            re 0;
    re 1;
}

int main () {
    scanf ("%d", &n);
    m = 0;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        scanf ("%d", &x[i]);
        cnt[x[i]]++;
        sum += x[i];
    }   
    for (int i = MAX - 1; i > 0; i--) cnt[i] += cnt[i + 1];
    for (int i = 2; i <= MAX; i++)
        if (!f[i]) {
            q[r++] = i;
            for (int j = i; j <= MAX; j += i) {
                f[j] = 1;
                w[j] = i;
            }
        }   
    for (int i = MAX; i > 1; i--) {
        cnt[i / w[i]] += cnt[i];
        if (i != w[i]) cnt[w[i]] += cnt[i];
    }
    ll l = 0, r = sum;
    while (r - l > 1) {
        ll s = (l + r) / 2;
        if (good (s)) r = s; else l = s;
    }
    cout << r << endl;
    return 0;
}