#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int main() {
	int n;
	scanf("%d\n", &n);
	string s;
	getline(cin, s);
	int ans = 0, index = 1;
	while (index < (int)s.size()) {
		if (s[index - 1] == s[index]) {
			s.erase(index, 1);
			ans++;  
		} else {
			index++;
		}
	}
	printf("%d", ans);
	return 0;
}