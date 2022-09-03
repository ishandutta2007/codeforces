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
int m, l, r;

bitset<300000000> f;

int main () {
    f[0] = 1;
    for (int i = 3; i <= 20000; i += 2)
        if (!f[i])
            for (int j = i * i; j <= 300000000; j += 2 * i) f[j] = 1;
    scanf ("%d%d", &l, &r);
    int ans = 0;
    if (l <= 2 && r >= 2) ans++;
    for (int i = 5; i <= r; i += 4) ans += int (!f[i] && i >= l);
    printf ("%d\n", ans);
    return 0;
}