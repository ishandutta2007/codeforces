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
int was[10];

int cool (int x) {
    while (x) {
        if (was[x % 10]) re 1;
        x /= 10;
    }
    re 0;
}

int main () {
    scanf ("%d", &n);
    m = n;
    while (m) {
        was[m % 10] = 1;
        m /= 10;
    }
    int ans = 0;
    for (int i = 1; i * i <= n; i++)
        if (n % i == 0) {
            ans += cool (i);
            if (i * i != n) ans += cool (n / i);
        }
    printf ("%d\n", ans);
    return 0;
}