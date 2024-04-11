#include <iostream>

int freq[16];
int cur_freq[4];

int main() {
	int n, k;
	std::cin >> n >> k;
	for(int i = 0; i < n; i++) {
		int cur = 0;
		for(int j = 0; j < k; j++) {
			int temp;
			std::cin >> temp;
			cur = cur * 2 + temp;
		}
		freq[cur]++;
	}
	for(int i = 1; i < (1 << 16); i++) {
		//std::cout << "on " << i << "\n";
		bool ok = true;
		int tot = 0;
		for(int j = 0; j < 4; j++) {
			cur_freq[j] = 0;
		}
		for(int j = 0; j < 16; j++) {
			if((i & (1 << j)) == 0)
				continue;
			ok = ok && freq[j] > 0;
			for(int kk = 0; kk < 4; kk++) {
				if((j & (1 << kk)) == 0)
					continue;
				cur_freq[kk]++;
			}
			tot++;
		}
		for(int j = 0; j < 4; j++) {
			ok = ok && cur_freq[j] <= tot / 2;
		}
		if(ok) {
			std::cout << "YES\n";
			return 0;
		}
	}
	std::cout << "NO\n";
}