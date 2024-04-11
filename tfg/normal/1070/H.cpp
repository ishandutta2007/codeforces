#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>
#include <map>
#include <set>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 100100 * 50;
int c = 1;
std::map<char, int> to[ms];
std::string ans[ms];
int hmm[ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	while(n--) {
		std::set<int> idx;
		std::string str;
		std::cin >> str;
		int s = (int) str.size();
		for(int l = 0; l < s; l++) {
			int st = 0;
			for(int r = l; r < s; r++) {
				if(!to[st].count(str[r])) {
					to[st][str[r]] = c++;
				}
				st = to[st][str[r]];
				idx.insert(st);
			}
		}
		for(auto p : idx) {
			ans[p] = str;
			hmm[p]++;
		}
	}
	int m;
	std::cin >> m;
	while(m--) {
		std::string str;
		std::cin >> str;
		int st = 0;
		for(auto ch : str) {
			if(!to[st].count(ch)) {
				st = -1;
				break;
			}
			st = to[st][ch];
		}
		if(st == -1) {
			std::cout << "0 -\n";
		} else {
			std::cout << hmm[st] << ' ' << ans[st] << "\n";
		}
	}
}