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
string s, t;
int c1[200000];
int c2[200000];

int main () {
    cin >> n >> s >> t;
    double ans = 0;
    double sum = 0;
    for (int i = 1; i <= n; i++) sum += (ll)i * i;
    for (int c = 0; c < 26; c++) {
        for (int i = 0; i < n; i++)
            if (s[i] - 'A' == c && t[i] - 'A' == c) ans += (ll)(i + 1) * (n - i) / sum;
        ll s1 = 0, s2 = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] - 'A' == c) s1 += n - i;
            if (t[i] - 'A' == c) s2 += n - i;
        }   
        for (int i = 0; i < n; i++) {
            if (s[i] - 'A' == c) s1 -= n - i;
            if (t[i] - 'A' == c) s2 -= n - i;
            if (s[i] - 'A' == c) ans += (ll)(i + 1) * s2 / sum;
            if (t[i] - 'A' == c) ans += (ll)(i + 1) * s1 / sum;
        }
    }
    printf ("%.10f\n", ans);
    return 0;
}