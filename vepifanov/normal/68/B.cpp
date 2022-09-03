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

int n;
int m;
int x[10000];

int main() {
    scanf ("%d%d", &n, &m);
    double p = (100 - m) / 100.0;
    for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
    double l = 0, r = 1000;
    for (int it = 0; it < 200; it++) {
        double s = (l + r) / 2;
        double cur = 0;
        for (int i = 0; i < n; i++)
            if (x[i] > s)
                cur += (x[i] - s) * p;
            else
                cur -= s - x[i];    
        if (cur < 0) r = s; else l = s;
    }
    printf ("%.10f\n", l);
    return 0;
}