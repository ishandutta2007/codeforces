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

const int N = 1000000;

int n;
int m;
int f[N + 2];

int main () {
    scanf ("%d%d", &n, &m);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        int x;
        scanf ("%d", &x);
        f[x]++;
        sum += x;
    }
    for (int i = N; i >= 0; i--) f[i] += f[i + 1];
    int ans = 1;
    for (int i = 2; i <= N; i++) {
        if (f[i] < n) break;
        int ok = 1;
        if (i > m)
            for (int j = i; j < N; j += i)
                if (f[min (j + m + 1, N + 1)] - f[min (j + i, N + 1)] > 0)
                    ok = 0;
        if (ok) ans = i;
    }
    printf ("%d\n", ans);
    return 0;
}