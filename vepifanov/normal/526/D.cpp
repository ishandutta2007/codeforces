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
string s;
int p[1000000];

int main () {
    cin >> n >> m >> s;
    p[0] = -1;
    for (int i = 1; i < n; i++) {
        int k = p[i - 1];
        while (k >= 0 && s[k + 1] != s[i]) k = p[k];
        if (s[k + 1] == s[i]) k++;
        p[i] = k;
    }
    int l = 1, r = 1;
    for (int i = 1; i <= n; i++) {
        int len = i - p[i - 1] - 1;
        int ok = 0;
        if (i >= m) {
            while (i / l > m) l++;
            while (i / (r + 1) >= m) r++;
//          printf ("%d = %d = %d %d\n", i, len, l, r);
            if (l <= r && (l + len - 1) / len <= r / len)
                ok = 1;
            if (i % m == 0 && (i / m) % len == 0) ok = 1;
            if (i % (m + 1) == 0 && (i / (m + 1)) % len == 0) ok = 1;
        }
//      printf ("%s = %d\n", s.substr (0, i).c_str (), i - p[i - 1] - 1);
        printf ("%d", ok);
    }
    printf ("\n");
    return 0;
}