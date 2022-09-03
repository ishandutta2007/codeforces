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
int s;
int M;
int cnt[2][1 << 6];

int go (int t, int i, int prev, int mask, int f, int cur) {
    if (i == 0) {
        if ((f | prev) == M - 1) cnt[t][mask] = min (cnt[t][mask], cur);
        re 0;
    }
    for (int j = 0; j < M; j++)
        if ((j | prev) == M - 1) {
            int tmp = 0, J = j;
            while (J) { tmp += J & 1; J /= 2; }
            go (t, i - 1, mask | j | ((j << 1) & (M - 1)) | (j >> 1), j, f, cur + tmp);
        }
    re 0;
}


int main () {
    scanf ("%d%d", &n, &m); 
    if (n < m) swap (n, m);
    M = (1 << m);
    s = n / 2;
    int ans = n * m;
    for (int i = 0; i < M; i++) {
        int cur = 0, I = i;
        while (I) { cur += I & 1; I /= 2; }
        for (int t = 0; t < 2; t++)
            for (int j = 0; j < M; j++)
                cnt[t][j] = n * m;
        go (0, s, M - 1, 0, i, 0);
        go (1, n - s - 1, M - 1, 0, i, 0);
        for (int a = 0; a < M; a++)
            for (int b = 0; b < M; b++)
                if ((a | b | i | (i >> 1) | ((i << 1) & (M - 1))) == M - 1)
                    ans = min (ans, cnt[0][a] + cnt[1][b] + cur);
    }
    printf ("%d\n", n * m - ans);
    return 0;
}