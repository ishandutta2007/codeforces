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

const int MAX = 1000000;
const int mod = 1073741824;

int n;
int m;

int f[MAX + 1];
int res[MAX + 1];
int a, b, c;

int main () {
    res[1] = 1;
    for (int i = 2; i <= MAX; i++) {
        if (!f[i]) {
            f[i] = i;
            if (i <= MAX / i)
                for (int j = i * i; j <= MAX; j += i) f[j] = i;
        }
        int j = i, k = 1;
        while (j % f[i] == 0) {
            j /= f[i];
            k++;
        }
        res[i] = res[j] * k;
    }
    scanf ("%d%d%d", &a, &b, &c);
    ll ans = 0;
    for (int i = 1; i <= a; i++)
        for (int j = 1; j <= b; j++)
            for (int k = 1; k <= c; k++)
                ans += res[i * j * k];
    cout << ans % mod << endl;
    return 0;
}