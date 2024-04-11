#include <iostream>
#include <string>
#include <bitset>
#include <iomanip>
#include <ctime>
#include <cstdlib>

typedef long double ld;

const int me = 20;
const int ms = 1 << me;

std::bitset<ms> masks[me];
std::string str[50];
int bits[ms];
ld prob[ms];
long long freq[ms];

int main() {
	srand(time(0));
	for(int i = 0; i < ms; i++) {
		bits[i] = bits[i / 2] + i % 2;
		for(int j = 0; j < me; j++) {
			if(i & (1 << j)) {
				masks[j][i] = 1;
			}
		}
	}
	int n;
	std::cin >> n;
	if(n == 1) {
		std::cout << "0\n";
		return 0;
	}
	for(int i = 0; i < n; i++) {
		std::cin >> str[i];
		//for(int j = 0; j < 20; j++) str[i] = 'a' + rand() % 52;
	}
	int m = str[0].size();
	prob[0] = 1;
	for(int i = 1; i < m; i++) {
		prob[i] = prob[i - 1] * (ld) i / (ld) (m - i + 1);
	}
	for(int i = 0; i < n; i++) {
		std::bitset<ms> curmask(false);
		for(int j = 0; j < n; j++) {
			if(i == j) continue;
			int equalMask = 0;
			for(int k = 0; k < m; k++) {
				if(str[i][k] == str[j][k]) {
					equalMask |= 1 << k;
				}
			}
			curmask[equalMask] = true;
		}
		for(int j = 0; j < me; j++) {
			curmask |= (curmask & masks[j]) >> (1 << j);
		}
		for(int j = 0; j < ms; j++) {
			if(curmask[j]) {
				//std::cout << "for " << i << " got " << j << std::endl;
				freq[bits[j]]++;
			}
		}
	}
	ld ans = 0;
	for(int i = m - 1; i >= 0; i--) {
		ans += freq[i] * prob[i];
	}
	std::cout << std::fixed << std::setprecision(20) << ans / n << std::endl;
}