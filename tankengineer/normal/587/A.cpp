#include<map>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int n;

int main() {
	scanf("%d", &n);
	map<int, int> tr;
	for (int i = 0; i < n; ++i) {
		int a;
		scanf("%d", &a);
		++tr[a];
	}
	int ans = 0;
	for (map<int, int>::iterator it = tr.begin(); it != tr.end(); ++it) {
		ans += it->second & 1;
		if (it->second > 1) {
			tr[it->first + 1] += it->second >> 1;
		}
	}
	printf("%d\n", ans);
	return 0;
}