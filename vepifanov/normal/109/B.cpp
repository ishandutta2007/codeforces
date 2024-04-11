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

const int MAX = 100000000;

int m;
int a1, b1, a2, b2, n;
vi v;

int go (int x) {
    v.pb (x);
    if (x <= MAX) { 
        go (x * 10 + 4);
        go (x * 10 + 7);
    }
    re 0;
}

ll calc (ll a1, ll b1, ll a2, ll b2) {
    if (a1 > b1 || a2 > b2) re 0;
    a2 = max (a2, a1);
    b1 = min (b1, b2);
    if (b1 < a2) re (b1 - a1 + 1) * (b2 - a2 + 1);
    re (a2 - a1) * (b2 - a2 + 1) + (b2 - a2 + b2 - b1 + 2) * (b1 - a2 + 1) / 2;
}

int main () {
    scanf ("%d%d%d%d%d", &a1, &b1, &a2, &b2, &n);
    m = 0;
    go (0);
    v.pb (MAX * 10 + 1);
    sort (all (v));
    ll cnt = (ll)(b1 - a1 + 1) * (b2 - a2 + 1);
    ll sum = 0;
    for (int i = 1; i + n < sz (v); i++) {
        int j = i + n - 1;
        sum += calc (max (a1, v[i - 1] + 1), min (b1, v[i]), max (a2, v[j]), min (b2, v[j + 1] - 1));
        sum += calc (max (a2, v[i - 1] + 1), min (b2, v[i]), max (a1, v[j]), min (b1, v[j + 1] - 1));
        if (n == 1 && a1 <= v[i] && b1 >= v[i] && a2 <= v[i] && b2 >= v[i]) sum--;
    }
    printf ("%.10f\n", (sum + 0.0) / cnt);
    return 0;
}