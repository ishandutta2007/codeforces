#include<bitset>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

bitset<100> p[100];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		p[i].reset();
		int m;
		scanf("%d", &m);
		for (int j = 0; j < m; ++j) {
			int a;
			scanf("%d", &a);
			p[i].set(a - 1);	
		}
	}
	for (int i = 0; i < n; ++i) {
		bool flag = false;
		for (int j = 0; j < n && !flag; ++j) {
			if (i == j) {
				continue;
			}
			if ((p[i] & p[j]) == p[j]) {
				flag = true;
			}
		}
		puts(!flag ? "YES" : "NO");
	}
	return 0;
}