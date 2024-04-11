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

vi v[100001];
vector<pair<vi, vi> > res;
int x[100000];
int was[100000];

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf ("%d", &x[i]); x[i]--;
    }
    for (int i = 0; i < n; i++)
        if (!was[i]) {
            int k = 0, j = i;
            while (!was[j]) {
                was[j] = 1;
                k++;
                j = x[j];
            }
            v[k].pb (j);
        }
    for (int i = n; i > 1; i--)
        while (sz (v[i]) > 0) {
            int a = v[i][sz (v[i]) - 1];
            v[i].pop_back ();
            if (i <= 3) {
                if (sz (v[2])) {
                    int b = v[2][sz (v[2]) - 1];
                    v[2].pop_back ();
                    if (i == 3) {
                        vi p (5), q (5);
                        p[0] = a; p[1] = x[a]; p[2] = x[x[a]]; p[3] = b; p[4] = x[b];
                        q[1] = a; q[2] = x[a]; q[0] = x[x[a]]; q[4] = b; q[3] = x[b];
                        int t = x[x[x[a]]];
                        x[x[x[a]]] = x[x[a]];
                        x[x[a]] = x[a];
                        x[a] = t;
                        t = x[x[b]];
                        x[x[b]] = x[b];
                        x[b] = t;
                        res.pb (mp (p, q));
                    } else {
                        vi p (4), q (4);
                        p[0] = a; p[1] = x[a]; p[2] = b; p[3] = x[b];
                        q[1] = a; q[0] = x[a]; q[3] = b; q[2] = x[b];
                        int t = x[x[a]];
                        x[x[a]] = x[a];
                        x[a] = t;
                        t = x[x[b]];
                        x[x[b]] = x[b];
                        x[b] = t;
                        res.pb (mp (p, q));
                    }   
                } else 
                if (i == 3 && sz (v[3])) {
                    int b = v[3][sz (v[3]) - 1];
                    v[3].pop_back ();
                    vi p (5), q (5);
                    p[0] = a; p[1] = x[a]; p[2] = x[x[a]]; p[3] = b; p[4] = x[b];
                    q[1] = a; q[2] = x[a]; q[0] = x[x[a]]; q[4] = b; q[3] = x[b];
                    int t = x[x[x[a]]];
                    x[x[x[a]]] = x[x[a]];
                    x[x[a]] = x[a];
                    x[a] = t;
                    t = x[x[b]];
                    x[x[b]] = x[b];
                    x[b] = t;
                    res.pb (mp (p, q));
                    v[2].pb (b);
                } else {
                    if (i == 3) {
                        vi p (3), q (3);
                        p[0] = a; p[1] = x[a]; p[2] = x[x[a]];
                        q[1] = a; q[2] = x[a]; q[0] = x[x[a]];
                        int t = x[x[x[a]]];
                        x[x[x[a]]] = x[x[a]];
                        x[x[a]] = x[a];
                        x[a] = t;
                        res.pb (mp (p, q));
                    } else {
                        vi p (2), q (2);
                        p[0] = a; p[1] = x[a];
                        q[1] = a; q[0] = x[a];
                        int t = x[x[a]];
                        x[x[a]] = x[a];
                        x[a] = t;
                        res.pb (mp (p, q));
                    }   
                }
            } else
            if (i > 5) {
                vi p (5), q (5);
                p[0] = a; p[1] = x[a]; p[2] = x[x[a]]; p[3] = x[x[x[a]]]; p[4] = x[x[x[x[a]]]];
                q[1] = a; q[2] = x[a]; q[3] = x[x[a]]; q[4] = x[x[x[a]]]; q[0] = x[x[x[x[a]]]];
                int t = x[x[x[x[x[a]]]]];
                x[x[x[x[x[a]]]]] = x[x[x[x[a]]]];
                x[x[x[x[a]]]] = x[x[x[a]]];
                x[x[x[a]]] = x[x[a]];
                x[x[a]] = x[a];
                x[a] = t;
                res.pb (mp (p, q));
                v[i - 4].pb (a);
            } else
            if (i == 5) {
                vi p (5), q (5);
                p[0] = a; p[1] = x[a]; p[2] = x[x[a]]; p[3] = x[x[x[a]]]; p[4] = x[x[x[x[a]]]];
                q[1] = a; q[2] = x[a]; q[3] = x[x[a]]; q[4] = x[x[x[a]]]; q[0] = x[x[x[x[a]]]];
                int t = x[x[x[x[x[a]]]]];
                x[x[x[x[x[a]]]]] = x[x[x[x[a]]]];
                x[x[x[x[a]]]] = x[x[x[a]]];
                x[x[x[a]]] = x[x[a]];
                x[x[a]] = x[a];
                x[a] = t;
                res.pb (mp (p, q));
            } else
            if (i == 4) {
                vi p (4), q (4);
                p[0] = a; p[1] = x[a]; p[2] = x[x[a]]; p[3] = x[x[x[a]]];
                q[1] = a; q[2] = x[a]; q[3] = x[x[a]]; q[0] = x[x[x[a]]];
                int t = x[x[x[x[a]]]];
                x[x[x[x[a]]]] = x[x[x[a]]];
                x[x[x[a]]] = x[x[a]];
                x[x[a]] = x[a];
                x[a] = t;
                res.pb (mp (p, q));
            }           
        }
    printf ("%d\n", sz (res));
    for (int i = 0; i < sz (res); i++) {
        printf ("%d\n", sz (res[i].fi));
        for (int j = 0; j < sz (res[i].fi); j++)
            printf ("%d ", res[i].se[j] + 1);
        printf ("\n");
        for (int j = 0; j < sz (res[i].se); j++)
            printf ("%d ", res[i].fi[j] + 1);
        printf ("\n");
    }
    return 0;
}