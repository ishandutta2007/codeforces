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
string s;
int x[50];
int was[51][10][2];
ll res[51][10][2];

int go (int i, int j, int k) {
    if (x[i] != j) k = 0;
    if (i + 1 == n) re 1 - k;
    if (was[i][j][k]) re res[i][j][k];
    was[i][j][k] = 1;
    ll cur = 0;
    cur += go (i + 1, (j + x[i + 1]) / 2, k);
    if ((j + x[i + 1]) & 1) cur += go (i + 1, (j + x[i + 1] + 1) / 2, k);
    res[i][j][k] = cur;
    re cur;
}

int main() {
    cin >> s;   
    n = sz (s);
    for (int i = 0; i < n; i++) x[i] = s[i] - '0';
    ll ans = 0;
    for (int i = 0; i < 10; i++) ans += go (0, i, 1);
    cout << ans << endl;
    return 0;
}