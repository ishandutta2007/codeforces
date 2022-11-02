#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
inline int count_1s(int x) { return __builtin_popcount(x); }
inline int count_1s(ull x) { return __builtin_popcountll(x); }
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }
#ifndef ONLINE_JUDGE
#	define debug(args...) fprintf(stderr, "%3d| ", __LINE__); fprintf(stderr, args); fprintf(stderr, "\n");
#else
#	define debug(args...)
#endif

char grid[103][103];
int n;

int main() {
	int i, j;
	scanf("%d", &n);
	bool hasDotAll = true;
	for(i = 0; i < n; i++) {
		bool hasDot = false;
		for(j = 0; j < n; j++) {
			scanf(" %c", &grid[i][j]);
			if(grid[i][j] == '.') hasDot = true;
		}
		if(!hasDot) hasDotAll = false;
	}
	if(hasDotAll) {
		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++)
				if(grid[i][j] == '.') {
					printf("%d %d\n", i + 1, j + 1);
					break;
				}
		return 0;
	}
	hasDotAll = true;
	for(j = 0; j < n; j++) {
		bool hasDot = false;
		for(i = 0; i < n; i++) {
			if(grid[i][j] == '.') hasDot = true;
		}
		if(!hasDot) hasDotAll = false;
	}
	if(hasDotAll) {
		for(j = 0; j < n; j++)
			for(i = 0; i < n; i++)
				if(grid[i][j] == '.') {
					printf("%d %d\n", i + 1, j + 1);
					break;
				}
		return 0;
	}
	puts("-1");
	return 0;
}