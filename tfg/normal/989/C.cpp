#include <iostream>
#include <vector>

const int dx[] = {0, -1, 0, 1};
const int dy[] = {-1, 0, 1, 0};
const int ms = 50;

void build(std::vector<std::string> &v, char a, char b, int f) {
	std::string first, second;
	if(f == 0) {
		for(int i = 0; i < ms; i++) {
			first += b;
			second += b;
		}
	} else {
		for(int i = 0; i < ms; i++) {
			first += a;
			second += b;
		}
		f--;
		for(int i = 2; f > 0; f--, i += 2) {
			first[i] = b;
		}
		first[0] = first[ms - 1] = b;
	}
	v.push_back(first);
	v.push_back(second);
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::vector<std::string> ans;
	int need[4], cur[4];
	cur[0] = cur[1] = cur[2] = cur[3] = 0;
	cur[0] = 1;
	std::cin >> need[0] >> need[1] >> need[2] >> need[3];
	need[0]--;
	need[3]--;
	for(int i = 1; i < 4; i++) {
		while(need[i] > 0) {
			int use = std::min(20, need[i]);
			build(ans, 'A' + i, 'A', use);
			need[i] -= use;
		}
	}
	build(ans, 'D', 'D', 0);
	while(need[0] > 0) {
		int use = std::min(20, need[0]);
		build(ans, 'A', 'D', use);
		need[0] -= use;
	}
	std::cout << ans.size() << ' ' << ms << "\n";
	for(int i = 0; i < ans.size(); i++) {
		std::cout << ans[i] << std::endl;
	}
}