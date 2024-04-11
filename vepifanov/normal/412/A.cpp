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
string s;

int main () {
    cin >> n >> m >> s; m--;
    printf ("PRINT %c\n", s[m]);
    if (m > n - m - 1) {
        for (int i = m + 1; i < n; i++) {
            printf ("RIGHT\n");
            printf ("PRINT %c\n", s[i]);
        }
        if (m > 0) {
            for (int i = n - 2; i >= m; i--)
                printf ("LEFT\n");
            for (int i = m - 1; i >= 0; i--) {
                printf ("LEFT\n");
                printf ("PRINT %c\n", s[i]);
            }
        }
    } else {
        for (int i = m - 1; i >= 0; i--) {
            printf ("LEFT\n");
            printf ("PRINT %c\n", s[i]);
        }
        if (m + 1 < n) {
            for (int i = 1; i <= m; i++)
                printf ("RIGHT\n");
            for (int i = m + 1; i < n; i++) {
                printf ("RIGHT\n");
                printf ("PRINT %c\n", s[i]);
            }
        }
    }
    return 0;
}