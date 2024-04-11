#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

std::vector<int> getBorder(const std::string &str) {
	int n = str.size();
	std::vector<int> border(n, -1);
	for(int i = 1, j = -1; i < n; i++) {
		while(j >= 0 && str[i] != str[j + 1]) {
			j = border[j];
		}
		if(str[i] == str[j + 1]) {
			j++;
		}
		border[i] = j;
	}
	return border;
}

int matchPattern(std::string txt, const std::string &pat, const std::vector<int> &border) {
	int freq = 0;
	for(int i = 0, j = -1; i < (int) txt.size(); i++) {
		while(j >= 0 && txt[i] != pat[j + 1]) {
			j = border[j];
		}
		if(pat[j + 1] == txt[i]) {
			j++;
		}
		if(j + 1 == (int) pat.size()) {
			//found occurence
			freq++;
			j = border[j];
		}
	}
	return freq;
}

std::string cut(std::string s, int p, bool pref = true) {
	if(!pref) {
		std::reverse(s.begin(), s.end());
	}
	while((int) s.size() >= p) {
		s.pop_back();
	}
	if(!pref) {
		std::reverse(s.begin(), s.end());
	}
	return s;
}

const int ms = 210;
std::string pref[ms], suf[ms];
long long trans[ms];

int bk = 0;

long long getFreq(int n, std::string pat, long long k) {
	std::vector<long long> f(n + 1, 0);
	if(pat == "0") {
		f[0]++;
	}
	if(pat == "1") {
		f[1]++;
	}
	auto border = getBorder(pat);
	for(int i = 2; i <= n; i++) {
		long long cur = trans[i - 2];
		if(i < bk + 4) {
			std::string curString = cut(suf[i - 2], (int) pat.size(), false) + cut(pref[i - 1], (int) pat.size(), true);
			cur = matchPattern(curString, pat, border);
		}
		f[i] = f[i - 1] + f[i - 2] + cur;
		if(f[i] > k) {
			return k + 1;
		}
		//std::cout << "got " << f[i] << std::endl;
		trans[i] = cur;
	}
	return std::min(f[n], k + 1);
}

int main() {
	pref[0] = suf[0] = "0";
	pref[1] = suf[1] = "1";
	for(int i = 2; i < ms; i++) {
		pref[i] = cut(pref[i - 2] + pref[i - 1], ms, true);
		suf[i] = cut(suf[i - 2] + suf[i - 1], ms, false);
		if(pref[i] == pref[i - 2] && suf[i] == suf[i - 1] && bk == 0) {
			bk = i;
		}
	}
	//std::cout << "bk is " << bk << std::endl;
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	long long k;
	//std::cin >> n >> k;
	std::cin >> n >> k >> m;
	n = std::min(n, 110);
	//std::cout << "n is " << n << std::endl;
	//std::cout << suf[n] << std::endl;
	if(n == 0) {
		std::cout << "0\n";
		return 0;
	} else if(n == 1) {
		std::cout << "1\n";
		return 0;
	}
	//m = (int) suf[n].size();
	std::string ans;
	k--;
	while(k >= 0 && (int) ans.size() < m) {
		//std::cout << "starting with " << ans << std::endl;
		//std::cout << "comparing (" << suf[n].substr(suf[n].size() - ans.size(), ans.size()) << ", " << ans << ")\n";
		if(ans.size() > 0 && suf[n].substr(suf[n].size() - ans.size(), ans.size()) == ans) {
			//std::cout << "got in end!\n";
			k--;
		}
		if(k < 0) {
			break;
		}
		ans += '0';
		long long got = getFreq(n, ans, k);
		//std::cout << "got " << got << " with " << ans << std::endl;
		//std::cout << "k is " << k << std::endl;
		if(got <= k) {
			ans.back() = '1';
			k -= got;
		}
	}
	std::cout << ans << std::endl;
}