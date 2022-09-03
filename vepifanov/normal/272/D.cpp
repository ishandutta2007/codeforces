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
int f[200001];
int q[200001];
int o;
map<int, int> all;
vi v[200001];

int power (int a, int b) {
    int c = 1;
    while (b) {
        if (b & 1) c = ((ll)c * a) % m;
        a = ((ll)a * a) % m;
        b /= 2;
    }
    re c;
}

int get (int x) {
    if (all.find (x) != all.end ()) re all[x];
    all[x] = o++;
    re o - 1;
}

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf ("%d", &x);
        v[get (x)].pb (i);
    }
    for (int i = 0; i < n; i++) {
        int x;
        scanf ("%d", &x);
        v[get (x)].pb (i);
    }
    scanf ("%d", &m);
    f[0] = 1;
    q[0] = 0;
    for (int i = 1; i <= 2 * n; i++) {
        int k = i, t = 0;
        while (k % 2 == 0) {
            k /= 2;
            t++;
        }
        f[i] = ((ll)f[i - 1] * k) % m;
        q[i] = q[i - 1] + t;
    }
    int ans = 1;
    for (int i = 0; i < o; i++) {
        sort (all (v[i]));
        int tmp = 0;
        for (int j = 0; j + 1 < sz (v[i]); j++)
            if (v[i][j] == v[i][j + 1])
                tmp++;
        ans = ((ll)ans * f[sz (v[i])]) % m;
        ans = ((ll)ans * power (2, q[sz (v[i])] - tmp)) % m;
    }
    printf ("%d\n", ans);
        return 0;
}