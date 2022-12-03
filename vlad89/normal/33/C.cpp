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
#define UN(a) SORT(a),(a).resize(unique(all(a))-(a).begin())
#define sz(a) ((int) (a).size())
#define pb push_back
#define CL(a,b) memset ((a), (b), sizeof (a))
#define X first
#define Y second

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

int a[123456];
int b[123456];

int main() {
#ifdef LocalHost
	freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
	int n;
	scanf ("%d", &n);
	REP (i, n)
		scanf ("%d", a + i);
	int S = 0;
	int res = 0;
	REP (i, n) {		
		b[i] = res;
		res += a[i];
		S += a[i];	
		res = max (res, -S);
	}
	int ans = S;
	ans = max (ans, res);
	int g = 0;
	for (int i = n-1; i >= 0; --i) {
		g -= a[i];
		ans = max (ans, g + b[i]);
	}
	cout << ans << endl;
	return 0;
}