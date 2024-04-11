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

const int N = 100000;

int n;
int m;

ll x[100000];
bitset<100001> w[60];
int cnt[60];
int q[60];
int p[100000];
int use[100000];

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) scanf ("%I64d", &x[i]);
    m = 0;
    for (int i = 0; i < 60; i++)
        for (int j = 0; j < n; j++)
            cnt[i] += (x[j] >> i) & 1;
    for (int i = 59; i >= 0; i--)
        if (cnt[i] % 2 == 0 && cnt[i] > 0)
            q[m++] = i;
    for (int i = 59; i >= 0; i--)
        if (cnt[i] % 2 == 1)
            q[m++] = i;
    for (int i = 0; i < 60; i++)
        if (cnt[i] == 0)
            q[m++] = i;
    for (int i = 0; i < 60; i++)
        for (int j = 0; j < n; j++)
            w[i][j] = (x[j] >> q[i]) & 1;
    for (int i = 0; i < n; i++) p[i] = i;
    for (int i = 0; i < 60; i++) {
        int k = -1;
        for (int j = 0; j < n; j++)
            if (w[i][j]) {
                k = j;
                break;
            }
        if (k == -1) continue;
        swap (p[i], p[k]);
        for (int j = 0; j < 60; j++) {
            int t = w[j][i];
            w[j][i] = w[j][k];
            w[j][k] = t;
        }   
        w[i][N] = 1 - w[i][N];
        for (int j = i + 1; j < 60; j++)        
            if (w[j][i])
                w[j] ^= w[i];
    }
    for (int i = 59; i >= 0; i--)
        if (w[i][i]) {
            if (w[i][N]) use[p[i]] = 1;
            for (int j = i - 1; j >= 0; j--)
                if (w[j][i])
                    w[j] ^= w[i];
        }
    for (int i = 0; i < n; i++) printf ("%d ", use[i] + 1);
    printf ("\n");
    return 0;
}