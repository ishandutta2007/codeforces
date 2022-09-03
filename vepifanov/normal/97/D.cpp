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

bitset<151> f[151], w[151], fn[151], cur[151];
string g[151];
string s;

int main () {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) cin >> g[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (g[i][j] == '#')
                w[i][j] = 1;
            else {
                f[i][j] = 1;
                if (g[i][j] == 'E') fn[i][j] = 1;
            }   
        for (int i = 0; i < n; i++) cur[i] = f[i];
        cin >> s;
    int ok = 1;
    for (int i = 0; i < n; i++)
        if (cur[i] != fn[i])
            ok = 0;
    if (ok) {
        printf ("%d\n", 0);
        re 0;
    }
        for (int it = 0; it < k; it++) {
            if (s[it] == 'L') 
                for (int i = 0; i < n; i++)
                    cur[i] = ((cur[i] >> 1) & f[i]) | (((cur[i] >> 1) & w[i]) << 1);
            if (s[it] == 'R') 
                for (int i = 0; i < n; i++)
                    cur[i] = ((cur[i] << 1) & f[i]) | (((cur[i] << 1) & w[i]) >> 1);
            if (s[it] == 'U')
                for (int i = 1; i + 1 < n; i++)
                    cur[i] = (cur[i + 1] & f[i]) | (cur[i] & w[i - 1]);
            if (s[it] == 'D')
                for (int i = n - 2; i > 0; i--)
                    cur[i] = (cur[i - 1] & f[i]) | (cur[i] & w[i + 1]);
            int ok = 1;
            for (int i = 0; i < n; i++)
                if (cur[i] != fn[i])
                    ok = 0;
            if (ok) {
                printf ("%d\n", it + 1);
                re 0;
            }
        }
        printf ("-1\n");
    return 0;
}