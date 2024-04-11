#include<map>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int main() {
	int n, k;
	map<int, int> tr;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i) {
		int t1;
		scanf("%d", &t1);
		++tr[t1];
	}
	if (k == 0) {
		if (tr.begin()->first == 1000000000) {
			printf("-1\n");
		} else {
			printf("1000000000 0\n");
		}
	} else {
		map<int, int>::reverse_iterator it;
		for (it = tr.rbegin(); it != tr.rend(); ++it) {
			k -= it->second;
			if (k <= 0) {
				break;
			}
		}
		if (it == tr.rend()) {
			printf("-1\n");
		} else {
			printf("%d %d\n", it->first, it->first);
		}
	}
	return 0;
}