#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <set>
#include <map>
#include <vector>
#include <algorithm>

int p;

long long fexp(long long x, int e = p - 2) {
	long long ans = 1;
	for(; e > 0; e /= 2) {
		if(e & 1) {
			ans = ans * x % p;
		}
		x = x * x % p;
	}
	return ans;
}

std::map<int, int> lul;
std::vector<int> s;

bool find(int u, int v, int k = 0, int d = 1) {
	//std::cout << u << std::endl;
	if(u == v || (lul.count(u) == 1 && abs(lul[u]) + k + 1 <= 200)) {
		if(u == v) return true;
		int x = lul[u];
		//std::cout << "second type, " << x << std::endl;
		u = fexp(u);
		if(x < 0) {
			for(int i = 0; i < -x; i++) {
				s.push_back(1);
			}
		} else {
			for(int i = 0; i < x; i++) {
				s.push_back(2);
			}
		}
		s.push_back(3);
		return true;
	}
	else if(k > 200) return false;
	else {
		int t = rand() % 100;
		bool ans;
		if(t <= 90) {
			ans = find((u+p+d)%p, v, k + 1, d);
			if(ans) s.push_back(d == 1 ? 1 : 2);
		} else {
			ans = find(fexp(u), v, k + 1, rand() % 2 * 2 - 1);
			if(ans) s.push_back(3);
		}
		return ans;
	}
}

long long getRand() {
	return (long long) rand() ^ ((long long) rand() << 16);
}

bool prime(int x) {
	for(int i = 2; i * i <= x; i++) {
		if(x % i == 0) return false;
	}
	return true;
}

int main() {
	srand(time(0));
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int u, v;
	std::cin >> u >> v >> p;
	if(u == v) {
		std::cout << "2\n1 2\n";
		return 0;
	}
	/*if(1) {
		p = getRand() % int(9e8) + 1e8;
		while(!prime(p)) {
			p++;
		}
		u = getRand() % p;
		v = getRand() % p;
	}*/
	//std::cout << u << ", " << v << ", " << p << std::endl;
	for(int i = -150; i <= 150; i++) {
		int x = fexp(((v + i % p) % p + p) % p);
		if(lul.count(x) == 0 || abs(lul[x]) > abs(i)) lul[x] = i;
	}
	while(1) {
		s.clear();
		while(!find(u, v, rand() % 2 * 2 - 1)) {
			//std::cout << "nope\n";
		}
		if(s.size() > 200) {
			continue;
		} else {
			break;
		}
	}
	//std::cout << "found!\n";
	std::reverse(s.begin(), s.end());
	std::cout << s.size() << "\n";
	for(int i = 0; i < s.size(); i++) {
		std::cout << s[i] << (i + 1 == s.size() ? '\n' : ' ');
		if(s[i] == 1) {
			u = (u+1)%p;
		} else if(s[i] == 2) {
			u = (u+p-1)%p;
		} else {
			u = fexp(u);
		}
	}
	//std::cout << u << ", " << v << ", " << p << std::endl;
}