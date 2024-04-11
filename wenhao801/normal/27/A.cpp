//#include "pch.h"

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int main() {
	int n;
	int i, j;
	bool b[10010] = {};
	cin >> n;
	for (i = 1; i <= n; i++) {
		cin >> j;
		b[j] = true;
	}
	for (i = 1; b[i]; i++);
	cout << i << endl;
	return 0;
}