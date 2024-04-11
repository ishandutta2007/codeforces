#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>
#include <cassert>

using namespace std;

map <string, bool> was;

const int MAXN = 2e5;

string s[MAXN];
char r[10];

int main() {
	//assert(freopen("input.txt", "r", stdin));
	//assert(freopen("output.txt", "w", stdout));
	
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", r);
		s[i] = string(r);
	}
	
	for (int i = n - 1; i >= 0; i--)
		if (!was[s[i]]) {
			for (int j = 0; j < int(s[i].size()); j++)
				printf("%c", s[i][j]);
			printf("\n");
			was[s[i]] = true;
		}
	
	return 0;
}