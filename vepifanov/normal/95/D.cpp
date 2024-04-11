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

const int mod = 1000000000 + 7;

int n;
int m;

int was[1010][1010][2][2];
int res[1010][1010][2][2];
int ct;
string s, t;

int go (const string& s, int i, int j, int p, int q) {
    if (i == sz (s)) re q;
    if (p == 0 && was[sz (s) - i][j][p][q] == ct || p == 1 && was[sz (s) - i][j][p][q]) re res[sz (s) - i][j][p][q];
    was[sz (s) - i][j][p][q] = ct;
    ll cur = 0;
    for (int k = 0; k < 10; k++)
        if (p == 1 || k <= s[i] - '0') {
            int np = p | int (k < s[i] - '0');
            int nq = q;
            int nj = min (1000, j + 1);
            if (k == 4 || k == 7) {
                nq |= int (nj != 1000 && nj <= m);
                nj = 0;
            }   
            cur += go (s, i + 1, nj, np, nq); 
        }
//  cout << s << " " << i << " " << j << " " << p << " " << q << " = " << cur << endl;
    re res[sz (s) - i][j][p][q] = cur % mod;
}

int main () {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s >> t;
        reverse (all (s));
        s[0]--;
        for (int j = 0; j < sz (s); j++)
            if (s[j] < '0') {
                s[j] += 10;
                s[j + 1]--;
            }
        reverse (all (s));
        ct++;
        int ans = go (t, 0, 1000, 0, 0);
        ct++;
        ans -= go (s, 0, 1000, 0, 0);
        if (ans < 0) ans += mod;
        cout << ans << endl;
    }
    return 0;
}