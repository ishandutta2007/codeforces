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
vi w[200], v[3];
int need[200];
int was[200];
int use[200];

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf ("%d", &x); x--;
        v[x].pb (i);
    }   
    for (int i = 0; i < n; i++) {
        scanf ("%d", &m);
        need[i] = m;
        for (int j = 0; j < m; j++) {
            int x;
            scanf ("%d", &x); x--;
            w[x].pb (i);
        }
    }
    int ans = 1e9;
    for (int t = 0; t < 3; t++) {
        memset (was, 0, sizeof (was));
        memset (use, 0, sizeof (use));
        int cur = 0, cnt = 0;
        for (int i = t; ; i = (i + 1) % 3) {
            while (true) {
                int ok = 0;
                for (int j = 0; j < sz (v[i]); j++) {
                    int k = v[i][j];
                    if (!was[k] && use[k] == need[k]) {
                        cnt++;
                        ok = 1;
                        cur++;
                        was[k] = 1;
                        for (int o = 0; o < sz (w[k]); o++)
                            use[w[k][o]]++;
                    }
                }   
                if (!ok) break;
            }
            if (cnt == n) break;
            cur++;
        }
        ans = min (ans, cur);
    }
    printf ("%d\n", ans);
    return 0;
}