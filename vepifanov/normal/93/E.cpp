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

const int MAX = 100000;

ll n;
int k;

int x[100];

char was[MAX + 1][100];
ll res[MAX + 1][100];

ll go (ll x, int y) {
    if (x == 0) re 0;
    if (y == k) re x;
    if (x <= MAX && was[x][y]) re res[x][y];
    ll cur = go (x, y + 1) - go (x / ::x[y], y + 1);
    if (x <= MAX) {
        was[x][y] = 1;
        res[x][y] = cur;
    }
    re cur;
}

int main () {
    cin >> n >> k;
    for (int i = 0; i < k; i++) cin >> x[i];
    sort (x, x + k);
    reverse (x, x + k);
    cout << go (n, 0) << endl;
    return 0;
}