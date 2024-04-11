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
int f[MAX + 1];
ll res[MAX + 1];

int main () {
    for (int i = 2; i <= MAX; i++)
        if (!f[i]) {
            f[i] = i;
            if (i <= MAX / i)
                for (int j = i * i; j <= MAX; j += i) 
                    f[j] = i;
        }
    res[1] = 1;
    for (int i = 2; i <= MAX; i++)
        if (f[i] <= i / f[i] && i % (f[i] * f[i]) == 0)
            res[i] = res[i / (f[i] * f[i])];
        else
            res[i] = f[i] * res[i / f[i]];
    scanf ("%d%d", &n, &m);
    ll ans = 0;
    for (int i = n; i < n + m; i++) ans += res[i];
    cout << ans << endl;
    return 0;
}