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
ll cnt[27];
int last[26];
int g[300000][26];
string s;


int main () {
    cin >> s;
    n = sz (s);
    for (int i = 0; i < 26; i++) last[i] = n;
    for (int i = n - 1; i >= 0; i--) {
        last[s[i] - 'a'] = i;
        for (int j = 0; j < 26; j++)
            g[i][j] = last[j];
    }
    for (int i = 0; i < n; i++) {
        int mask = 1 << (s[i] - 'a'), cur = 1;
        int j = i;
        while (j < n) {
            int k = n, ch = 0;
            for (int t = 0; t < 26; t++)
                if (((mask >> t) & 1) == 0 && g[j][t] < k) {
                    k = g[j][t];
                    ch = t;
                }
            cnt[cur] += k - j;
            cur++;
            mask |= 1 << ch;
            j = k;
        }
    }
    int ans = 0;
    while (ans < 26 && cnt[ans + 1]) ans++;
    printf ("%d\n", ans);
    for (int i = 1; i <= 26; i++)
        if (cnt[i] != 0)
            printf ("%I64d\n", cnt[i]);
    return 0;
}