#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int x, t, a, b, da, db;
	cin >> x >> t >> a >> b >> da >> db;
	for (int i = 0; i < t; ++i) {
		for (int j = 0; j < t; ++j) {
			if (a - da * i + b - db * j == x || a - da * i == x || b - db * j == x || x == 0) {
				printf("YES\n");
				return 0;
			}
		}
	}
	printf("NO\n");
	return 0;
}