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
#define prev PREV
                         
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
int g[26][26];
string s, t;

int main () {
    cin >> n;
    cin >> s >> t;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        g[s[i] - 'a'][t[i] - 'a'] = i + 1;
        ans += int (s[i] != t[i]);
    }
    for (int i = 0; i < 26; i++)
        for (int j = i + 1; j < 26; j++)
            if (g[i][j] && g[j][i]) {
                printf ("%d\n", ans - 2);
                printf ("%d %d\n", g[i][j], g[j][i]);
                re 0;
            }
    for (int i = 0; i < 26; i++)
        for (int j = 0; j < 26; j++)
            if (i != j)
                for (int k = 0; k < 26; k++)
                    if (j != k && g[i][j] && g[j][k]) {
                        printf ("%d\n", ans - 1);
                        printf ("%d %d\n", g[i][j], g[j][k]);
                        re 0;
                    }
    printf ("%d\n-1 -1\n", ans);
    return 0;
}