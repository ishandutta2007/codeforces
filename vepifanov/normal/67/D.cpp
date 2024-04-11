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
int a[1000001];
int b[1000001];
int c[1000001];
int d[1000001];
int res[1000001];


int main() {
    scanf ("%d", &n);   
    for (int i = 0; i < n; i++) {
        scanf ("%d", &a[i]);
        d[a[i] - 1] = i;
    }
    for (int i = 0; i < n; i++) scanf ("%d", &b[i]);
    for (int i = 0; i < n; i++) c[d[b[i] - 1]] = n - i - 1;
    for (int i = 0; i <= n; i++)
        res[i] = n;
    res[0] = -1;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int l = 0, r = i + 1;
        while (r - l > 1) {
            int s = (l + r) / 2;
            if (res[s] < c[i]) l = s; else r = s;
        }
        res[r] = min (res[r], c[i]);
        ans = max (ans, r);
    }   
    printf ("%d\n", ans);
    return 0;
}