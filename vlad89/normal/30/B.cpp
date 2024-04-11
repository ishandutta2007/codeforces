#define _CRT_SECURE_NO_DEPRECATE
#pragma comment (linker, "/STACK:256000000")
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
#define UN(a) sort(all(a)),(a).resize(unique(all(a))-(a).begin())
#define sz(a) ((int) (a).size())
#define pb push_back
#define CL(a,b) memset ((a), (b), sizeof (a))
#define X first
#define Y second

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

const int days[2][12] = {
							{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
							{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
bool isleap (int year) {
	if (year % 4 == 0)
		return true;
	return false;
}

bool is_correct (int day, int month, int year) {
	if (month > 12) return false;
	bool leap = isleap (year);
	month--;
	if (day > days[leap][month]) return false;
	return true;
}

int main() {
#ifdef LocalHost
	freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
#endif
	int day, month, year;
	scanf ("%d.%d.%d", &day, &month, &year);
	int a[3];
	scanf ("%d.%d.%d", a+0,a+1,a+2);
	sort (a, a + 3);
	do {
		int d = a[0];
		int m = a[1];
		int y = a[2];
		if (!is_correct (d, m, y))
			continue;
		if (year - y - 1 + (month > m || (m == month && day >= d)) >= 18) {
			puts ("YES");
			return 0;
		}
	} while (next_permutation (a, a + 3));
	puts ("NO");
	return 0;
}