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

const int N = 10*1000*1000;

int n;
int m;
int cnt[N + 1];
int w[N + 1];
int f[N + 1];

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf ("%d", &x);
        w[x]++;
    }
    for (int i = 2; i <= N; i++)
        if (!f[i]) {
            f[i] = i;
            if (i <= N / i)
                for (int j = i * i; j <= N; j += i)
                    f[j] = i;
        }
    for (int i = N; i > 1; i--)
        if (w[i]) {
            cnt[f[i]] += w[i];
            int j = i, k = f[i];
            while (j % k == 0) j /= k;
            w[j] += w[i];
        }
    for (int i = 1; i <= N; i++) cnt[i] += cnt[i - 1];
    scanf ("%d", &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf ("%d%d", &a, &b);
        a = min (a, N + 1);
        b = min (b, N);
        printf ("%d\n", cnt[b] - cnt[a - 1]);
    }
    return 0;
}