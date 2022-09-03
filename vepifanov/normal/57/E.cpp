#include <cstdio>
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

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < n; i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define y0 y3487465
#define y1 y8687969

typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) {
    re x > 0 ? x : -x;
}

const int di[8] = {2, 1, -1, -2, -2, -1, 1, 2};
const int dj[8] = {1, 2, 2, 1, -1, -2, -2, -1};

const int mod = 1000000007;
const int MAX = 200;

ll n;
int m;
bool was[4 * MAX + 1][4 * MAX + 1];
bool forb[4 * MAX + 1][4 * MAX + 1];
short d[4 * MAX + 1][4 * MAX + 1];
pair<short, short> q[sqr (4 * MAX + 1)];
int cnt[MAX + 1];


int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf ("%d%d", &a, &b);
        a += 2 * MAX; b += 2 * MAX;
        forb[a][b] = 1;
    }
    int l = 0, r = 1;
    q[0] = mp (2 * MAX, 2 * MAX);
    was[2 * MAX][2 * MAX] = 1;
    while (l < r) {
        int i = q[l].fi;
        int j = q[l].se;
        cnt[d[i][j]]++;
        l++;
        if (d[i][j] == n || d[i][j] == MAX) continue;
        for (int k = 0; k < 8; k++) {
            int ni = i + di[k];
            int nj = j + dj[k];
            if (!was[ni][nj] && !forb[ni][nj]) {
                was[ni][nj] = 1;
                d[ni][nj] = d[i][j] + 1;
                q[r++] = mp (ni, nj);
            }
        }
    }
    if (n > MAX && cnt[MAX] > 0) {
        int tmp = (n - MAX) % mod;
        r = (r + (ll)tmp * cnt[MAX]) % mod;
        r = (r + ((ll)tmp * (tmp + 1)) % mod * 14) % mod;
    }
    printf ("%d\n", r);
    return 0;
}