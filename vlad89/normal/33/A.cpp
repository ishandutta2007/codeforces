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

int ma[1024];

int main() {
#ifdef LocalHost
	freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
	int n, m, k;
	cin >> n >> m >> k;
	REP (i, m)
		ma[i] = -1u/4;
	REP (i, n) 
	{
		int r, c;
		scanf ("%d%d", &r, &c);
		--r;
		ma[r] = min (ma[r], c);
	}
	long long res = 0;
	REP (i, m)
		res += ma[i];
	res = min (res, (long long)k);
	cout << res << endl;
	return 0;
}