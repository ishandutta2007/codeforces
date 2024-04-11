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
int m, k;
int w[401][401];
string s[400];
int cnt[26];

int main () {
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = n - 1; i >= 0; i--)
        for (int j = 0; j < m; j++)
            w[i][j] = w[i + 1][j] + int (s[i][j] == 'a');
    ll ans = 0;
    for (int a = 0; a < n; a++)
        for (int b = a + 1; b < n; b++) {
            int y = -1, cur = 0;
            memset (cnt, 0, sizeof (cnt));
            for (int x = 0; x < m; x++) {
                while (y + 1 < x || y + 1 < m && cur + w[a][y + 1] - w[b + 1][y + 1] <= k) {
                    y++;
                    cur += w[a][y] - w[b + 1][y];
                    if (s[a][y] == s[b][y]) cnt[s[a][y] - 'a']++;
                }
                if (s[a][x] == s[b][x] && y > x) ans += cnt[s[a][x] - 'a'] - 1;
                cur -= w[a][x] - w[b + 1][x];
                if (s[a][x] == s[b][x]) cnt[s[a][x] - 'a']--;
            }
        }
    cout << ans << endl;
    return 0;
}