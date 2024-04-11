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

const int N = 1000000;
const int M = 200000;
const int MAXK = 15;

int n;
int m;
int wn[N + 1];
int un[N + 1];
ll p[N + 1];
ll q[N + 1];
int a, b, c;
int cnt[M];
ll x[N + 1];
ll pr[15];
ll ans;

ll gcd (ll a, ll b) { re a ? gcd (b % a, a) : b; }

int get (ll x, ll y) {
    if (x <= y / x) re wn[x];
    re un[y / x];
}

int go (ll y) {
    ll Y = y;
    a = b = c = 0;
    for (int i = 2; (ll)i * i <= Y; i++)
        if (Y % i == 0) {
            pr[c++] = i;
            while (Y % i == 0) Y /= i;
        }
    if (Y > 1) pr[c++] = Y;
    for (int i = 1; (ll)i * i <= y; i++)
        if (y % i == 0) {
            p[a++] = i;
            if ((ll)i * i != y) q[b++] = y / i;
        }
    for (int i = b - 1; i >= 0; i--) p[a++] = q[i];
    for (int i = 0; i < a; i++) {
        cnt[i] = 0;
        if (p[i] <= y / p[i]) { 
            wn[p[i]] = i;
        } else {
            un[y / p[i]] = i;
        }   
    }
    for (int i = 0; i < n; i++) {
        ll d = gcd (x[i], y);
        cnt[get (d, y)]++;
    }   
    for (int i = 0; i < c; i++) 
        for (int j = a - 1; j >= 0; j--)
            if (p[j] % pr[i] == 0)
                cnt[get (p[j] / pr[i], y)] += cnt[j];
    for (int j = 0; j < a; j++)
        if (2 * cnt[j] >= n)
            ans = max (ans, p[j]);
    re ans;
}

int main () {
//  srand (239017);
    double start = clock ();
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) scanf ("%I64d", &x[i]);
    random_shuffle (x, x + n);
    ans = 1;
    for (int i = 0; i < n; i++) {
        go (x[i]);
        if ((clock () - start) / CLOCKS_PER_SEC > 3.5) break;
    }   
    cout << ans << endl;
    cerr << clock () << endl;
    return 0;
}