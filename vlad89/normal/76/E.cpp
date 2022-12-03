#define _CRT_SECURE_NO_DEPRECATE
#include <functional>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <sstream>
#include <numeric>
#include <cstdlib>
#include <cstdio>
#include <bitset>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
#include <list>
#include <set>
#include <map>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define all(a) (a).begin(),(a).end()
#define UN(a) SORT(a),(a).resize(unique(all(a))-a.begin())
#define sz(a) ((int) (a).size())
#define pb push_back
#define CL(a,b) memset (a, b, sizeof (a))
#define X first
#define Y second

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

int x[123456], y[123456];

int main() {
    #ifdef LocalHost
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    long long res = 0;
    int n;
    scanf ("%d", &n);
    ll Sx = 0, Sy = 0;
    REP (i, n) {
        scanf ("%d%d", &x[i], &y[i]);
        res += x[i]*x[i] + y[i]*y[i];        
        Sx += x[i];
        Sy += y[i];
    }
    res *= 2*n;
    REP (i, n)
        res -= 2 * x[i] * Sx + 2 * y[i] * Sy;
    res /= 2;
    cout << res << endl;
    return 0;
}