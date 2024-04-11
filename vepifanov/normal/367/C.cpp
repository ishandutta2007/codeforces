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
int x[100000];

int main () {
    scanf ("%d%d", &n, &m);
        for (int i = 0; i < m; i++) {
            int a, b;
            scanf ("%d%d", &a, &b);
            x[i] = b;
        }
        sort (x, x + m);
        reverse (x, x + m);
        ll ans = 0;
        for (int i = 1; i <= m; i++) {
                int cur = i * (i - 1) / 2;
                if (i % 2 == 0) cur += i / 2 - 1;
                if (cur + 1 > n) break;
                ans += x[i - 1];
        }
        cout << ans << endl;
    return 0;
}