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
int m, k, t;
int x[1000], y[1000];

int main() {
        scanf ("%d%d%d%d", &n, &m, &k, &t);
        for (int i = 0; i < k; i++) scanf ("%d%d", &x[i], &y[i]);
        for (int i = 0; i < t; i++) {
            int a, b;
            scanf ("%d%d", &a, &b);
            int res = (a - 1) * m + b, bad = 0;
            for (int j = 0; j < k; j++)
                if (x[j] < a || x[j] == a && y[j] < b)
                    res--;
                else
                if (x[j] == a && y[j] == b) bad = 1;    
            if (bad) printf ("Waste\n"); else
            if (res % 3 == 1) printf ("Carrots\n"); else
            if (res % 3 == 2) printf ("Kiwis\n"); else
            if (res % 3 == 0) printf ("Grapes\n");
        }
    return 0;
}