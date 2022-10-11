#include <iostream>
#include <vector>

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int pos = -1;
	int n, m;
	std::cin >> n >> m;
	std::string s, t;
	std::cin >> s >> t;
	for(int i = 0; i < n; i++) {
		if(s[i] == '*') {
			pos = i;
		}
	}
	bool valid = false;
	if(pos == -1) {
		valid = s == t;
	} else if(n <= m + 1) {
		int end = n - (pos + 1);
		//std::cout << "comparing (" << s.substr(0, pos) << ", " << t.substr(0, pos) << "), (" << s.substr(pos + 1, n - (pos + 1)) << ", " << t.substr(m - end, end) << ")\n";
		valid = s.substr(0, pos) == t.substr(0, pos) && s.substr(pos + 1, n - (pos + 1)) == t.substr(m - end, end);
	}
	std::cout << (valid ? "YES" : "NO") << std::endl;
}