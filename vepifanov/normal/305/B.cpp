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
ll p, q;
ll x[100];

ll gcd (ll a, ll b) { re a ? gcd (b % a, a) : b; }

int main () {
    cin >> p >> q;
    ll d = gcd (p, q);
    p /= d;
    q /= d;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> x[i];
    ll p = x[n - 1], q = 1;
    double P = x[n - 1], Q = 1;
    for (int i = n - 2; i >= 0; i--) {
        swap (p, q);
        swap (P, Q);
        p += q * x[i];
        P += Q * x[i];
    }
    if (P <= 5e18 && Q <= 5e18 && p == ::p && q == ::q) printf ("YES\n"); else printf ("NO\n");
    return 0;
}