#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	string res;
	for (int i = 0; i < n; i++) {
		if ((i % 2) == 0) res += "I hate "; else res += "I love ";
		if (i + 1 < n) res += "that "; else res += "it ";
	}
	cout << res << endl;
}