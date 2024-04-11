#include <cstdio>
#include <iostream>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <queue>

using namespace std;

#define lld I64d

char s[100010];
int n;

int main() {
	scanf("%s", s);
	n = strlen(s);
	vector <char> v;
	for (int i = 0; i < n; i++) {
		if (v.empty()) {
			v.push_back(s[i]);
		} else if (v.back() == s[i]) {
			v.pop_back();
		} else {
			v.push_back(s[i]);
		}
	}
	if (v.empty()) {
		printf("Yes");
	} else {
		printf("No");
	}
	return 0;
}