#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> s(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &s[i]);
	}
	sort(s.begin(), s.end());
	for (int i = 0; i < n; ++i) {
		printf("%d%c", s[i], i == n - 1 ? '\n' : ' ');
	}
	return 0;
}