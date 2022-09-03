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
int g[500][500];
int res[501][501];
int prev[501][501];

string s;

int out (int i, int j) {
    if (i != 0) {
        int k = prev[i][j];
        out (prev[i][j], j - 1);
        if (prev[i][j] != 0) printf ("+");
        for (int t = k; t < i; t++) printf ("%c", s[min (t, i + k - t - 1)]);
    }
    re 0;
}
 
int main () {
    cin >> s >> m;
    n = sz (s);
    for (int l = 0; l < n; l++)
        for (int i = 0; i + l < n; i++) {
            int j = i + l;
            if (l == 0) g[i][j] = 0; else g[i][j] = g[i + 1][j - 1];
            g[i][j] += int (s[i] != s[j]);
        }
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            res[i][j] = 1e9;
    res[0][0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            for (int l = 0; l < i; l++)
                if (res[i][j] > res[l][j - 1] + g[l][i - 1]) {
                    res[i][j] = res[l][j - 1] + g[l][i - 1];
                    prev[i][j] = l;
                }
    int ans = 1e9, pos = 0;
    for (int i = 1; i <= m; i++)
        if (res[n][i] < ans) {
            ans = res[n][i];
            pos = i;
        }
    printf ("%d\n", ans);
    out (n, pos);
    printf ("\n");
    return 0; 
}