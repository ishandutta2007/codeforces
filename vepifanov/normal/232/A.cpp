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
int g[100][100];

int main () {
    scanf ("%d", &n);
    int a = 0;
    while ((a + 1) * a * (a - 1) / 6 <= n) a++;
    memset (g, 0, sizeof (g));
    for (int i = 0; i < a; i++)
        for (int j = 0; j < a; j++)
            if (i != j)
                g[i][j] = 1;
    n -= a * (a - 1) * (a - 2) / 6;
    m = a;
    while (n) {
        int b = 0;
        while (b < a && (b + 1) * b / 2 <= n) b++;
        n -= b * (b - 1) / 2;
        for (int i = 0; i < b; i++)
            g[i][m] = g[m][i] = 1;          
        m++;    
    }
    printf ("%d\n", m);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++)
            printf ("%d", g[i][j]);
        printf ("\n");
    }
    return 0;
}