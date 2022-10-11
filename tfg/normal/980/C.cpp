#include <iostream>
#include <map>
#include <cstdio>

int val[256];

int main() {
	int n, k;
	std::cin >> n >> k;
	for(int i = 1; i < 256; i++) {
		val[i] = -1;
	}
	for(int i = 0; i < n; i++) {
		int c;
		scanf("%d", &c);
		int pt = c;
		while(c - pt + 1 < k && val[pt] == -1) pt--;
		if(val[pt] != -1 && c - val[pt] + 1 > k) pt++;
		if(val[pt] == -1) {
			for(int j = pt; j <= c; j++) val[j] = pt;
		} else {
			for(int j = pt + 1; j <= c; j++) val[j] = val[pt];
		}
		printf("%d%c", val[c], i + 1 == n ? '\n' : ' ');
	}
}