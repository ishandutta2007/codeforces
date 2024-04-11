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

const int MAX = 2000000;

int n;
int m, x;
int z[200000];
int y[200000];
int f[MAX + 1];

int main() {
    int r = 0;
    for (int i = 2; i <= MAX; i++)
        if (!f[i]) {
            z[r++] = i;
            if ((ll)i * i <= MAX)
                for (int j = i * i; j <= MAX; j += i) f[j] = 1;
        }
    scanf ("%d%d", &n, &x); 
    for (int i = 0; i < n; i++) scanf ("%d", &y[i]);
    sort (y, y + n);
    if (x == 2) printf ("0\n"); else
    if (y[0] == 1) printf ("1\n"); else {
        int k = 0, ans = 0;
        for (int i = 0; z[i] < x; i++) {
            while (k < n && y[k] < z[i]) k++;
            if (k == n || y[k] > z[i]) {
                printf ("-1\n");
                re 0;
            }
            ans++;
        }
        printf ("%d\n", ans);
    }   
    return 0;
}