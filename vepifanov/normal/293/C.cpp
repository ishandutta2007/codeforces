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

ll n;
int q[1000000];

int main () {
    cin >> n;
    if (n % 3 != 0) {
        printf ("0\n");
        re 0;
    }
    n /= 3;
    int o = 0;
    for (int x = 2; (ll)x * x <= n; x++)
        if (n % x == 0) {
            q[o++] = x;
        }   
    sort (q, q + o);
    int ans = 0;
    for (int i = 0; i < o && (ll)q[i] * q[i] * q[i] <= n; i++) {
        int ab = q[i];
        ll nn = n / ab;
        for (int j = i; j < o && (ll)q[j] * q[j] <= nn; j++)
            if (nn % q[j] == 0) {
                int ac = q[j];
                int bc = nn / ac;
                if ((ab + ac + bc) % 2 == 0) {
                    int a = (ab + ac - bc) / 2;
                    int b = (ab + bc - ac) / 2;
                    int c = (ac + bc - ab) / 2;
                    if (a > 0 && b > 0 && c > 0 && a <= b && b <= c) {
                        if (a == b && b == c) ans++; else
                        if (a == b || b == c) ans += 3; else ans += 6;
                    }
                }
            }
    }
    cout << ans << endl;
//  cerr << clock () << endl;
    return 0;
}