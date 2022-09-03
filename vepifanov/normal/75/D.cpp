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
#define left LEFT
#define right RIGHT

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
ll left[50], right[50], mid[50], sum[50];
int l[50];
int p[250000];
int g[50][5000];

int main() {
    scanf ("%d%d", &n, &m); 
    for (int i = 0; i < n; i++) {
        scanf ("%d", &l[i]);
        for (int j = 0; j < l[i]; j++)
            scanf ("%d", &g[i][j]);
    }
    for (int i = 0; i < n; i++) {
        left[i] = mid[i] = right[i] = -1e18;
        ll cur;
        cur = 0;
        for (int j = 0; j < l[i]; j++) {
            cur += g[i][j];
            left[i] = max (left[i], cur);
        }
        cur = 0;
        for (int j = l[i] - 1; j >= 0; j--) {
            cur += g[i][j];
            right[i] = max (right[i], cur);
        }
        cur = 0;
        for (int j = 0; j < l[i]; j++) {
            if (cur < 0) cur = 0;
            cur += g[i][j];
            mid[i] = max (mid[i], cur);
        }
        cur = 0;
        for (int j = 0; j < l[i]; j++) cur += g[i][j];
        sum[i] = cur;
    }
    for (int i = 0; i < m; i++) scanf ("%d", &p[i]);
    ll cur = 0, ans = -1e8;
    for (int i = 0; i < m; i++) {
        int j = p[i] - 1;
        if (cur < 0) cur = 0;
        ans = max (ans, cur + left[j]);
        ans = max (ans, mid[j]);
        cur = max (cur + sum[j], right[j]);
    }
    cout << ans << endl;
    return 0;
}