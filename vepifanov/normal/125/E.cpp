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
int k;
int ea[100000];
int eb[100000];
int ec[100000];
int use[100000];
pair<double, int> v[100000];
int p[5000];

int gp (int x) {
    if (p[x] != x) p[x] = gp (p[x]);
    re p[x];
}

ii go (double h, int ok) {
    for (int i = 0; i < m; i++) {
        v[i] = mp (ec[i] + h * int (ea[i] == 0 || eb[i] == 0) + i * int (ea[i] != 0 && eb[i] != 0) / 10000000.0, i);
        use[i] = 0;
    }
    for (int i = 0; i < n; i++) p[i] = i;
    sort (v, v + m);
    int cnt = 0, res = 0, all = 0;
    for (int i = 0; i < m; i++) {
        int a = gp (ea[v[i].se]);
        int b = gp (eb[v[i].se]);
        int ir = int (ea[v[i].se] == 0 || eb[v[i].se] == 0);
        int c = ec[v[i].se];
        if (a != b) {
            use[v[i].se] = 1;
            res += c;
            cnt += ir;
            if (rand () & 1) p[a] = b; else p[b] = a;
        }
    }
    re mp (cnt, res);
}

int main () {
    scanf ("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        scanf ("%d%d%d", &ea[i], &eb[i], &ec[i]); 
        ea[i]--;
        eb[i]--;
    }   
    double l = -5e5, r = 5e5;
    for (int it = 0; it < 50; it++) {
        double s = (l + r) / 2;
        ii tmp = go (s, 0);
        if (tmp.fi > k) l = s; else r = s;
    }   
    ii tmp = go (r, 1);
    if (tmp.fi != k) printf ("-1"); else {
        printf ("%d\n", n - 1);
        for (int i = 0; i < m; i++)
            if (use[i])
                printf ("%d ", i + 1);
        printf ("\n");
    }   
    return 0;
}