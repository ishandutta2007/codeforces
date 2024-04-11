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
vi v;
int a, b;

int main() {
    scanf ("%d%d", &a, &b); 
    for (int i = 1; i * i <= a; i++)
        if (a % i == 0) {
            if (b % i == 0) v.pb (i);
            if (b % (a / i) == 0) v.pb (a / i);
        }
    sort (all (v));
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf ("%d%d", &x, &y);
        int l = 0, r = sz (v);
        while (r - l > 1) {
            int s = (l + r) / 2;
            if (v[s] <= y) l = s; else r = s;
        }
        if (v[l] >= x) printf ("%d\n", v[l]); else printf ("-1\n");
    }
    return 0;
}