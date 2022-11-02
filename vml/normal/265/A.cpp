#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	string s;
	getline(cin, s);
	string t;
	getline(cin, t);
	int index = 1;
	for (int i = 0; i < (int)t.size(); i++) {
		if (t[i] == s[index - 1]) {
			index++;
		}
	}
	printf("%d", index);
	return 0;
}