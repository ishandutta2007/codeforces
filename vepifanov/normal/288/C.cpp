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
int res[1000001];
ll ans = 0;

int go (int n) {
    if (n <= 0) re 0;
    int m = 1;
    while (m - 1 < n) m *= 2;
    int k = n;
    while (m - k - 1 <= n) {
        ans += m - 1;
        res[k] = m - k - 1;
        k--;
    }
    go (m - n - 2);
}

int main () {
    scanf ("%d", &n);
    go (n);
    cout << ans << endl;
    for (int i = 0; i <= n; i++) printf ("%d ", res[i]);
    printf ("\n");
    return 0;
}