#include <cstdio>
#include <numeric>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <deque>
#include <queue>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <cassert>
#include <functional>
#include <numeric>

using namespace std;

#ifdef __WIN32__
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

#ifdef __WIN32__
    #define ULLD "%I64u"
#else
    #define ULLD "%llu"
#endif

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define j0 j5743892
#define j1 j542893
                         
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }
template<class T> T gcd(T a, T b) { re a ? gcd (b % a, a) : b; }
template<class T> T sqr(T a) { re a * a; }

#define filename ""

int n;
int m;
int was[26];
vi v[26];
string s[100];
string ans;

int go (int x) {
    if (was[x] == 1) re 1;
    if (was[x] == 2) re 0;
    was[x] = 1;
    for (int i = 0; i < sz (v[x]); i++)
        if (go (v[x][i]))
            re 1;
    was[x] = 2;
    ans += char (x + 'a');
    re 0;
}

int main () {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i + 1 < n; i++) {
        int j = 0;
        while (j < sz (s[i]) && j < sz (s[i + 1]) && s[i][j] == s[i + 1][j]) j++;
        if (j == sz (s[i])) continue;
        if (j == sz (s[i + 1])) {
            printf ("Impossible\n");
            re 0;
        }
        v[s[i][j] - 'a'].pb (s[i + 1][j] - 'a');
    }
    for (int i = 0; i < 26; i++)
        if (!was[i] && go (i)) {
            printf ("Impossible\n");
            re 0;
        }
    reverse (all (ans));
    cout << ans << endl;
    return 0;
}