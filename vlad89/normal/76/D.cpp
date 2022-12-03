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

int main() {
    #ifdef LocalHost
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    unsigned long long a, b;
    cin >> a >> b;
    unsigned long long x = 0, y = b;
    if (a < b) {
        cout << -1 << endl;
        return 0;
    }
    a -= b;
    if (a & 1) {
        cout << -1 << endl;
        return 0;
    }
    a >>= 1;
    if (a & b) {
        cout << -1 << endl;
        return 0;
    }
    x += a;
    y += a;
    cout << x << ' ' << y << endl;
	return 0;
}