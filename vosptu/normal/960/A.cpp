// #include <iostream>
// #include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cassert>
#include <ctime>
// #include <unordered_map>
#include <map>
#include <queue>

using namespace std;

char S[5100];
int cnt[3];

int main() {
	scanf("%s", S);
	int n = strlen(S);
	for (int i = 0; i < n; i++)
		cnt[S[i] - 'a'] += 1;
	for (int i = 0; i < n - 1; i++)
		if (S[i] > S[i + 1]) {
			printf("NO\n");
			return 0;
		}
	if (cnt[0] > 0 && cnt[1] > 0 && (cnt[2] == cnt[0] || cnt[2] == cnt[1]))
		printf("YES\n");
	else
		printf("NO\n");
}