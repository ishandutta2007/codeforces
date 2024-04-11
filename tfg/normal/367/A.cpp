#include <iostream>
#include <cstdio>
#include <algorithm>

int dec[256];

int freq[100100][3];

int main() {
	std::string str;
	std::cin >> str;
	dec['x'] = 0;
	dec['y'] = 1;
	dec['z'] = 2;
	for(int i = 0; i < str.size(); i++) {
		freq[i + 1][dec[str[i]]]++;
		for(int j = 0; j < 3; j++) {
			freq[i + 1][j] += freq[i][j];
		}
	}
	int m;
	std::cin >> m;
	while(m--) {
		int l, r;
		//std::cin >> l >> r;
		scanf("%i %i", &l, &r);
		std::vector<int> freqs;
		for(int i = 0; i < 3; i++) {
			freqs.push_back(freq[r][i] - freq[l - 1][i]);
		}
		std::sort(freqs.begin(), freqs.end());
		if(freqs[2] - freqs[0] <= 1 || r - l + 1 < 3) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
}