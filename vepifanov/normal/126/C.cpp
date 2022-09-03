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
char w[2001][2001];
int x[2000][2000];
int use[2000];

int main () {
    scanf ("%d", &n);   
    gets (w[0]);
    for (int i = 0; i < n; i++) gets (w[i]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            x[i][j] = int (w[i][j] == '1');
    int ans = 0;
    memset (use, 0, sizeof (use));
    for (int i = 0; i < n; i++) {
        int cur = 0;
        for (int j = n - 1; j > i; j--)
            if (x[i][j] ^ use[j] ^ cur) {
                cur ^= 1;
                use[j] ^= 1;
                x[i][i] ^= 1;
                x[j][j] ^= 1;
                ans++;
            }
    }
    memset (use, 0, sizeof (use));
    for (int i = n - 1; i >= 0; i--) {
        int cur = 0;
        for (int j = 0; j < i; j++)
            if (x[i][j] ^ use[j] ^ cur) {
                cur ^= 1;
                use[j] ^= 1;
                x[i][i] ^= 1;
                x[j][j] ^= 1;
                ans++;
            }
    }
    for (int i = 0; i < n; i++)
        ans += x[i][i];
    printf ("%d\n", ans);
    return 0;
}