#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::string a, b, c;
	std::cin >> a >> b >> c;
	std::vector<int> freq(26, 0);
	for(auto ch : a) {
		freq[ch - 'a']++;
	}
	std::vector<int> freqb(26, 0);
	for(auto ch : b) {
		freqb[ch - 'a']++;
	}
	std::vector<int> freqc(26, 0);
	for(auto ch : c) {
		freqc[ch - 'a']++;
	}
	int ans[] = {0, 0};
	for(int i = 0; 1; i++) {
		int o = 12983712;
		for(int j = 0; j < 26; j++) {
			if(freqc[j]) {
				o = std::min(o, freq[j] / freqc[j]);
			}
		}
		if(o + i > ans[0] + ans[1]) {
			ans[0] = i;
			ans[1] = o;
		}

		bool wtf = true;
		for(int j = 0; j < 26; j++) {
			freq[j] -= freqb[j];
			if(freq[j] < 0) wtf = false;
		}
		if(!wtf) break;
	}
	freq.assign(26, 0);
	for(auto ch : a) {
		freq[ch - 'a']++;
	}
	a.clear();
	while(ans[0]--) {
		a += b;
	}
	while(ans[1]--) {
		a += c;
	}
	for(auto ch : a) {
		freq[ch - 'a']--;
	}
	for(int i = 0; i < 26; i++) {
		while(freq[i]--) {
			a += char(i + 'a');
		}
	}
	std::cout << a << '\n';
}