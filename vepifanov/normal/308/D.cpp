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

int main () {
    scanf ("%d%d", &n, &m);
    ll ans = 0;
    for (int a = m + 1; 2 * a <= n + 1; a++) {
        int r = 2 * a * (n + 1 - a);
        int c = n - m, b = m + 1;
        int cur = 0;
        int p = n + 1 - a;
        int q = a;
        int sum = p * b + q * c + b * c;
        while (b <= n - m) {
            while (c > m && sum >= r) {
                sum -= b + q;
                c--;
            }
            sum += c + p;
            b++;
            cur += c;
        }
        ans += (cur - (n - 2 * m) * m) * (1 + int (2 * a < n + 1));
    }   
    printf ("%I64d\n", ans * 3);
//  cerr << clock () << endl;
    return 0;
}