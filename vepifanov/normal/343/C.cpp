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
ll x[100000];
ll y[100000];

ll calc (ll a, ll b, ll c) { 
    if (a < b) re c - a;
    if (a > c) re a - b;
    re (c - b) + min (a - b, c - a);
}   

int can (ll h) {
    int j = 0;
    for (int i = 0; i < n; i++) {
        int k = j;
        while (k < m && calc (x[i], y[j], y[k]) <= h) k++;
        j = k;
    }
    if (j == m) re 1;
    re 0;
}

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf ("%I64d", &x[i]);
    for (int i = 0; i < m; i++) scanf ("%I64d", &y[i]);
    ll l = -1, r = 1e11;
    while (r - l > 1) {
        ll s = (l + r) / 2;
        if (can (s)) r = s; else l = s;
    }
    cout << r << endl;
    return 0;
}