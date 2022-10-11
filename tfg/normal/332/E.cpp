#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

std::string c[2020];
int rep[2020];
std::map<std::string, int> dec;

int main() {
	//std::ios::sync_with_stdio(0); std::cin.tie(0);
	std::string txt;
	std::string pat;
	int k;
	std::getline(std::cin, txt);
	std::getline(std::cin, pat);
	std::cin >> k;
	for(int i = 0; i < txt.size(); i++) {
		c[i % k].push_back(txt[i]);
	}
	std::vector<int> useable[2];
	for(int i = 0; i < txt.size() % k; i++) {
		useable[0].push_back(i);
		if(!dec.count(c[i])) {
			dec[c[i]] = i;
		}
		rep[i] = dec[c[i]];
	}
	for(int i = txt.size() % k; i < k; i++) {
		useable[1].push_back(i);
		if(!dec.count(c[i])) {
			dec[c[i]] = i;
		}
		rep[i] = dec[c[i]];
	}
	std::reverse(useable[0].begin(), useable[0].end());
	std::reverse(useable[1].begin(), useable[1].end());
	int cycles = txt.size() / k;
	std::string ans(k + 1, '2');
	for(int i = 0; i <= useable[0].size() && i + i * cycles <= pat.size(); i++) {
		int got = i + i * cycles;
		int rest;
		if(cycles != 0) {
			if((pat.size() - got) % cycles != 0) continue;
			rest = (pat.size() - got) / cycles;
		} else {
			if(i != pat.size()) continue;
			rest = 0;
		}
		bool can = true;
		std::vector<int> wuts(i + rest);
		for(int j = 0; j < rest + i && can; j++) {
			std::string haha;
			for(int k = j; k < pat.size(); k += rest + i) {
				haha += pat[k];
			}
			if(!dec.count(haha)) {
				can = false;
			} else {
				wuts[j] = dec[haha];
			}
		}
		if(!can) continue;
		std::string anss(k, '0');
		got = 0;
		for(int j = 0; j < useable[0].size() && got < i; j++) {
			if(rep[useable[0][j]] == wuts[i - got - 1]) {
				anss[useable[0][j]] = '1';
				got++;
			}
		}
		if(got < i) continue;
		got = 0;
		for(int j = 0; j < useable[1].size() && got < rest; j++) {
			if(rep[useable[1][j]] == wuts[i + rest - got - 1]) {
				anss[useable[1][j]] = '1';
				got++;
			}
		}
		if(got < rest) continue;
		ans = std::min(ans, anss);
	}
	if(ans.size() > k) ans = "0";
	std::cout << ans << std::endl;
}