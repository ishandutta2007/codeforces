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
string s[4], t[20];
int p[4];

int main () {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> s[i];
    cin >> m;
    int ans = 0, res = 0;
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) cin >> t[j];
        for (int j = 0; j < n; j++) p[j] = j;
        do {
            int cur = n * (n - 1) / 2 + 1;
            for (int j = 0; j < n; j++)
                for (int r = j + 1; r < n; r++)
                    if (p[j] > p[r])
                        cur--;
            int r = 0;
            for (int j = 0; j < k && r < n; j++)
                if (s[p[r]] == t[j])
                    r++;
            if (r == n && cur > ans) {
                ans = cur;
                res = i + 1;
            }
        } while (next_permutation (p, p + n));
    }
    if (ans == 0) printf ("Brand new problem!\n"); else printf ("%d\n[:%s:]\n", res, string (ans, '|').c_str ());
    return 0;
}