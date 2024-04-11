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
string s[100];

int main () {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> s[i];
    int x = 0, t = 1;
    ll ans = 0;    
    for (int i = 0; i + 1 < n; i++) {
        int a = x, b = x;
        while (true) {
//          printf ("%d %d = %d %d = %I64d\n", a, b, x, t, ans);
            if (s[i + 1][x] == '.') {
                ans++;
                break;
            }
            if ((a == 0 || s[i][a - 1] == '#') && (b + 1 == m || s[i][b + 1] == '#')) {
                printf ("Never\n");
                re 0;
            }
            if (t == 1) {
                ans += b - x;
                x = b;
                ans++;
                if (x + 1 < m && s[i][b + 1] == '.') x++, b++; else
                if (x + 1 < m && s[i][b + 1] == '+') {
                    s[i][b + 1] = '.';
                    t = -t;
                } else
                if (x + 1 == m || s[i][b + 1] == '#') t = -t;
            } else {
                ans += x - a;
                x = a;
                ans++;
                if (x - 1 >= 0 && s[i][a - 1] == '.') x--, a--; else
                if (x - 1 >= 0 && s[i][a - 1] == '+') {
                    s[i][a - 1] = '.';
                    t = -t;
                } else
                if (x == 0 || s[i][a - 1] == '#') t = -t;
            }
        }
    }
    cout << ans << endl;
    return 0;
}