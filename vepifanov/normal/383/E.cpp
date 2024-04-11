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
#include <cassert>

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

const int M = 1 << 12;
const int MM = 1 << 24;

int n;
int m;
int res[2][M];
int sum[2][M][12];
int c1[24];
int c2[24][24];
int c3[24][24][24];

int main () {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        sort (all (s));
        s.resize (unique (all (s)) - s.begin ());
        for (int a = 0; a < sz (s); a++) {
            c1[s[a] - 'a']++;
            for (int b = a + 1; b < sz (s); b++) {
                c2[s[a] - 'a'][s[b] - 'a']++;
                for (int c = b + 1; c < sz (s); c++)
                    c3[s[a] - 'a'][s[b] - 'a'][s[c] - 'a']++;
            }
        }
    }
    for (int i = 0; i < M; i++) {
        for (int a = 0; a < 12; a++) {
            if (((i >> a) & 1) == 0) continue;
            res[0][i] += c1[a];
            res[1][i] += c1[a + 12];
            for (int b = a + 1; b < 12; b++) {
                if (((i >> b) & 1) == 0) continue;
                res[0][i] -= c2[a][b];
                res[1][i] -= c2[a + 12][b + 12];
                for (int c = b + 1; c < 12; c++) {
                    if (((i >> c) & 1) == 0) continue;
                    res[0][i] += c3[a][b][c];
                    res[1][i] += c3[a + 12][b + 12][c + 12];
                }
            }
        }
        for (int a = 0; a < 12; a++)
            for (int b = 0; b < 12; b++) {
                if (((i >> b) & 1) == 0) continue;
                sum[0][i][a] -= c2[b][a + 12];
//              sum[1][i][a] -= c2[a][b + 12];
                for (int c = b + 1; c < 12; c++) {
                    if (((i >> c) & 1) == 0) continue;
                    sum[0][i][a] += c3[b][c][a + 12];
                    sum[1][i][a] += c3[a][b + 12][c + 12];
                }
            }
    }
    int ans = 0;
    for (int i = 0; i < MM; i++) {
        int i1 = i & (M - 1);
        int i2 = i >> 12;
        int cur = res[0][i1] + res[1][i2];
        for (int a = 0; a < 12; a++) {
            if ((i1 >> a) & 1) cur += sum[1][i2][a];
            if ((i2 >> a) & 1) cur += sum[0][i1][a];
        }
        ans ^= cur * cur;
    }
    printf ("%d\n", ans);
    return 0;
}