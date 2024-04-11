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

const int mod = 1000000000 + 7;

int n;
int m, la, lb, ra, rb;
int a[5000], b[5000];
int ans;
int p2[5001];

int check (int h) {
    ans = 0;
    if (ra - la <= h && rb - lb <= h) {
        ans = p2[n - 1] - 1;
        re 1;
    } else
    if (ra - la <= h) {
        int mid = 0, bad = 0;
        for (int i = 0; i < n; i++)
            if (b[i] >= rb - h && b[i] <= lb + h)
                mid++;
            else
            if (b[i] > lb + h && b[i] < rb - h)
                bad++;
        if (bad) re 0;
        ans = p2[mid];
        re 1;
    } else
    if (rb - lb <= h) {
        int mid = 0, bad = 0;
        for (int i = 0; i < n; i++)
            if (a[i] >= ra - h && a[i] <= la + h)
                mid++;
            else
            if (a[i] > la + h && a[i] < ra - h)
                bad++;
        if (bad) re 0;
        ans = p2[mid];
        re 1;
    }
    int cnt[2][2], ok = 0;
    memset (cnt, 0, sizeof (cnt));
    for (int i = 0; i < n; i++) {
        int p = int (a[i] <= la + h && b[i] <= lb + h);
        int q = int (a[i] >= ra - h && b[i] >= rb - h);
        cnt[p][q]++;
    }
    if (!cnt[0][0]) { ok = 1; ans += p2[cnt[1][1]]; }
    memset (cnt, 0, sizeof (cnt));
    for (int i = 0; i < n; i++) {
        int p = int (a[i] <= la + h && b[i] >= rb - h);
        int q = int (a[i] >= ra - h && b[i] <= lb + h);
        cnt[p][q]++;
    }
    if (!cnt[0][0]) { ok = 1; ans += p2[cnt[1][1]]; }
    ans %= mod;
    re ok;
}

int main() {
    p2[0] = 1;
    for (int i = 1; i <= 5000; i++) p2[i] = (p2[i - 1] * 2) % mod;
    scanf ("%d", &n);   
    la = 10000, lb = 10000, ra = -10000, rb = -10000;
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf ("%d%d", &x, &y);
        a[i] = x + y;
        b[i] = x - y;
        la = min (la, a[i]);
        ra = max (ra, a[i]);
        lb = min (lb, b[i]);
        rb = max (rb, b[i]);
    }
    int l = -1, r = 50000;
    while (r - l > 1) {
        int s = (l + r) / 2;
        if (check (s)) r = s; else l = s;
    }
    check (r);
    printf ("%d\n%d\n", r, (ans * 2) % mod);
    return 0;
}