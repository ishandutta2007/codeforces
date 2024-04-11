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

const int mod = 1000003;

int n;
int m;

char w[500001];
int g[500001];

int main () {
    scanf ("%d%d", &n, &m);
    gets (w);
    for (int i = 0; i < n; i++) {
        gets (w);
        for (int j = 0; j < m; j++) 
            if (w[j] == '.')
                g[i * m + j] = -1;
            else    
                g[i * m + j] = w[j] - '1';
    }
    int ans = 1;
    for (int i = 0; i < n; i++) {
        int ok1 = 1, ok2 = 1;
        for (int j = 0; j < m; j++)
            if (g[i * m + j] != -1)
                if (j & 1) {
                    if (g[i * m + j] != 0 && g[i * m + j] != 1) ok2 = 0;
                    if (g[i * m + j] != 2 && g[i * m + j] != 3) ok1 = 0;
                } else {
                    if (g[i * m + j] != 0 && g[i * m + j] != 1) ok1 = 0;
                    if (g[i * m + j] != 2 && g[i * m + j] != 3) ok2 = 0;
                }
        ans = (ans * (ok1 + ok2)) % mod;
    }
    for (int j = 0; j < m; j++) {
        int ok1 = 1, ok2 = 1;
        for (int i = 0; i < n; i++)
            if (g[i * m + j] != -1)
                if (i & 1) {
                    if (g[i * m + j] != 1 && g[i * m + j] != 2) ok2 = 0;
                    if (g[i * m + j] != 0 && g[i * m + j] != 3) ok1 = 0;
                } else {
                    if (g[i * m + j] != 1 && g[i * m + j] != 2) ok1 = 0;
                    if (g[i * m + j] != 0 && g[i * m + j] != 3) ok2 = 0;
                }
        ans = (ans * (ok1 + ok2)) % mod;
    }
    printf ("%d\n", ans);
    return 0;
}