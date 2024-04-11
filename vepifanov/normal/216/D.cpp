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

vi v[1000];
int l[1000];

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf ("%d", &l[i]);
        v[i].resize (l[i]);
        for (int j = 0; j < l[i]; j++) scanf ("%d", &v[i][j]);
        sort (all (v[i]));
    }   
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int ai = (i + n - 1) % n;
        int bi = (i + 1) % n;
        int al = 0, ar = -1, bl = 0, br = -1;
        for (int j = 0; j + 1 < l[i]; j++) {
            while (al < l[ai] && v[ai][al] < v[i][j]) al++;
            while (ar + 1 < l[ai] && v[ai][ar + 1] <= v[i][j + 1]) ar++;
            while (bl < l[bi] && v[bi][bl] < v[i][j]) bl++;
            while (br + 1 < l[bi] && v[bi][br + 1] <= v[i][j + 1]) br++;
            int ac = max (ar - al + 1, 0), bc = max (br - bl + 1, 0);
            if (ac != bc) ans++;
        }
    }
    printf ("%d\n", ans);
    return 0;
}