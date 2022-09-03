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

ll n, m;
map<pair<ll, int>, ll> all;

ll calc (ll len, ll cur, int k) {
    if (cur <= 0 || k < 0) re 0;
    if (len == 1) re int (k == 0);
    if (len == cur && all.find (mp (len, k)) != all.end ()) re all[mp (len, k)];
    ll ans = calc (len / 2, min (cur, len / 2), k) + calc (len / 2, cur - len / 2, k - 1);
    if (len == cur) all[mp (len, k)] = ans;
    re ans;
}

int main () {
    cin >> n >> m;
    int k = 1;
    while (m % 2 == 0) {
        k++;
        m /= 2;
    }
    if (m != 1) {
        printf ("0\n");
        re 0;
    }
    n += 2;
    ll cur = 1;
    while (cur <= n) cur *= 2;
    printf ("%I64d\n", calc (cur, n, k) - int (k == 1));
    return 0;
}