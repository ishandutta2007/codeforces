#include <iostream>
#include <map>
#include <string>

int main() {
	int ans = 0;
	int n;
	std::string str;
	std::cin >> n >> str;
	int cur = 0;
	std::map<int, int> last;
	last[0] = -1;
	for(int i = 0; i < n; i++) {
		cur += (str[i] == '0' ? -1 : 1);
		if(last.count(cur)) {
			ans = std::max(ans, i - last[cur]);
		} else {
			last[cur] = i;
		}
	}
	std::cout << ans << '\n';
}