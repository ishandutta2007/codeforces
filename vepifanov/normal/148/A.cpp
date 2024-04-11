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
int a, b, c, d;

int gcd (int a, int b) { re a ? gcd (b % a, a) : b; }

int nok (int a, int b) { re a * b / gcd (a, b); }

int main () {
    scanf ("%d%d%d%d%d", &a, &b, &c, &d, &n);
    printf ("%d\n", n / a + n / b + n / c + n / d - n / (nok (a, b)) - n / (nok (a, c)) - n / (nok (a, d)) - n / (nok (b, c)) - n / (nok (b, d)) - n / nok (c, d) + n / nok (a, nok (b, c)) + n / nok (a, nok (b, d)) + n / nok (a, nok (c, d)) + n / nok (b, nok (c, d)) - n / nok (nok (a, b), nok (c, d)));
    return 0;
}