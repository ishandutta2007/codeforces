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
string s[15], t[500000];
int last[15];
int res[1 << 15][106];
int next[500000][15];
int cnt[1 << 15][15];


int main () {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < (1 << n); i++)
        for (int j = 0; j < n; j++)
            for (int k = j + 1; k < n; k++)
                if ((i >> k) & 1)
                    cnt[i][j]++;
    cin >> m;
    int ans = 106, pos = 0;
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) cin >> t[j];
        for (int j = 0; j < n; j++) last[j] = k + 1;
        for (int j = k - 1; j >= 0; j--) 
            for (int p = 0; p < n; p++) {
                if (s[p] == t[j])
                    last[p] = j;
                next[j][p] = last[p];
            }
        for (int j = 0; j < (1 << n); j++)
            for (int p = 0; p < 106; p++)
                res[j][p] = k + 1;
        res[0][0] = 0;
        for (int j = 1; j < (1 << n); j++)
            for (int p = 0; p < 106; p++) 
                for (int x = 0; x < n; x++)
                    if (((j >> x) & 1) && p >= cnt[j][x]) {
                        int tmp = res[j - (1 << x)][p - cnt[j][x]];
                        if (tmp < k) tmp = next[tmp][x];
                        res[j][p] = min (res[j][p], tmp + 1);
                    }
        for (int j = 0; j < ans; j++)
            if (res[(1 << n) - 1][j] <= k) {
                ans = j;
                pos = i + 1;
                break;
            }
    }
    ans = n * (n - 1) / 2 - ans + 1;
    if (ans <= 0) printf ("Brand new problem!\n"); else printf ("%d\n[:%s:]\n", pos, string (ans, '|').c_str ());
    return 0;
}