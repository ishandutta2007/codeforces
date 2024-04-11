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
int k[3], t[3];
ll g[3][100000];
pair<ll, ll> v[3][100000];

int main() {
    for (int i = 0; i < 3; i++) 
        scanf ("%d", &k[i]);
    for (int i = 0; i < 3; i++)
        scanf ("%d", &t[i]);
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf ("%d", &x);
        v[0][i].se = v[0][i].fi = x;
    }   
    for (int i = 0; i < 3; i++) k[i] = min (k[i], n);
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < k[i]; j++)
            g[i][j] = 0;
    ll ans = 0;
    for (int i = 0; i < 3; i++) {
        sort (v[i], v[i] + n);
        int x = 0;
        for (int j = 0; j < n; j++) {
            ll cur = v[i][j].fi;
            cur = max (cur, g[i][x]);
            cur += t[i];
            g[i][x] = cur;
            x = (x + 1) % k[i];
            if (i < 2) v[i + 1][j] = mp (cur, v[i][j].se); else ans = max (ans, cur - v[i][j].se);
        }
    }
    cout << ans << endl;
    return 0;
}