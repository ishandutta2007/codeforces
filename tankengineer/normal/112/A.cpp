#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main() {
	string a, b;
	cin >> a >> b;
	for (int i = 0; i < a.size(); ++i) {
		if (a[i] >= 'a') a[i] = 'A' + a[i] - 'a';
	}
	for (int i = 0; i < b.size(); ++i) {
		if (b[i] >= 'a') b[i] = 'A' + b[i] - 'a';
	}
	if (a == b) {
		printf("%d\n", 0);
	} else if (a < b) {
		printf("%d\n", -1);
	} else {
		printf("%d\n", 1);
	}
	return 0;
}