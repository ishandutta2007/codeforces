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
#define prev PREV
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

const int N = 500*1000;

int n;
int m;

int f[N + 1];
int cnt[N + 1];
int res[N + 1];
int a[N + 1];
int q;

int main () {
    for (int i = 2; i <= N; i++)
        if (!f[i]) {
            f[i] = i;
            if (i <= N / i)
                for (int j = i * i; j <= N; j += i)
                    f[j] = i;
        }
    res[1] = 1;
    for (int i = 2; i <= N; i++) {
        int j = f[i];
        if ((i / j) % j == 0)
            res[i] = 0;
        else
            res[i] = -res[i / j];
    }
    scanf ("%d%d", &n, &q);
    for (int i = 0; i < n; i++) {
        scanf ("%d", &a[i]);
        f[i] = 1;
    }
    ll ans = 0;
    for (int i = 0; i < q; i++) {
        int k;
        scanf ("%d", &k); k--;
        if (f[k] == 1) {
            for (int j = 1; j * j <= a[k]; j++)
                if (a[k] % j == 0) {
                    ans += f[k] * cnt[j] * res[j];
                    if (j * j != a[k])
                        ans += f[k] * cnt[a[k] / j] * res[a[k] / j];
                }
            for (int j = 1; j * j <= a[k]; j++)
                if (a[k] % j == 0) {
                    cnt[j] += f[k];
                    if (j * j != a[k])
                        cnt[a[k] / j] += f[k];
                }
        } else {
            for (int j = 1; j * j <= a[k]; j++)
                if (a[k] % j == 0) {
                    cnt[j] += f[k];
                    if (j * j != a[k])
                        cnt[a[k] / j] += f[k];
                }
            for (int j = 1; j * j <= a[k]; j++)
                if (a[k] % j == 0) {
                    ans += f[k] * cnt[j] * res[j];
                    if (j * j != a[k])
                        ans += f[k] * cnt[a[k] / j] * res[a[k] / j];
                }
        }
        f[k] *= -1;
        cout << ans << "\n";
    }
    return 0;
}