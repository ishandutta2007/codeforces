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
int x[100001];
int cnt[500][100001];
int w[500];
int u[100001];
int o;
     
int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf ("%d", &x[i]);
        if (x[i] <= n) u[x[i]]++;
    }
    for (int i = 1; i <= n; i++)
        if (u[i] >= i) 
            w[o++] = i;
    for (int i = 0; i < o; i++) {
        cnt[i][n] = 0;
        for (int j = n - 1; j >= 0; j--)
            cnt[i][j] = cnt[i][j + 1] + int (x[j] == w[i]);
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf ("%d%d", &a, &b); a--; b--;
        int ans = 0;
        for (int j = 0; j < o; j++)
            if (cnt[j][a] - cnt[j][b + 1] == w[j])
                ans++;
        printf ("%d\n", ans);
    }
    
    return 0;
}