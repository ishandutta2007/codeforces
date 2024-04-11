#include<cstdio>
#include<vector>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int k, a, b;
	scanf("%d%d%d", &k, &a, &b);
	string s;
	cin >> s;
	if (k * a <= s.size() && s.size() <= k * b) {
		int n = s.size(), pos = 0;
		for (int i = k - 1; i >= 0; --i) {
			int key = a;
			while (n - key > i * b) {
				++key;
			}
			printf("%s\n", s.substr(pos, key).c_str());
			pos += key;
			n -= key;
		}
	} else {
		printf("No solution\n");
	}
	return 0;
}