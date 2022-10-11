#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

const int MOD = 1e9 + 7;

char str[21039];


int main() {
	//std::ios::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> buffer;
	int ans = 1;
	std::priority_queue<int> hp[2];
	while(n--) {
		int v;
		scanf(" %s %d", str, &v);
		if(str[1] == 'D') {
			// add
			//std::cout << "adding " << v << std::endl;
			if(hp[0].size() > 0 && hp[0].top() > v) {
				hp[0].push(v);
			} else if(hp[1].size() > 0 && -hp[1].top() < v) {
				hp[1].push(-v);
			} else {
				//std::cout << "in buffer\n";
				buffer.push_back(v);
			}
		} else {
			// delete
			std::sort(buffer.begin(), buffer.end());
			int pos = 0;
			while(pos < (int) buffer.size() && buffer[pos] != v) pos++;
			// check if valid
			if(pos == (int) buffer.size()) {
				if(hp[0].size() > 0 && hp[0].top() == v) {
					hp[0].pop();
				} else if(hp[1].size() > 0 && -hp[1].top() == v) {
					hp[1].pop();
				} else {
					std::cout << "0\n";
					return 0;
				}
			} else {
				ans = 2 * ans % MOD;
			}
			// delete same ones
			{
				for(auto e : buffer) {
					if(e < v) {
						hp[0].push(e);
					} else if(e > v) {
						hp[1].push(-e);
					}
				}
				buffer.clear();
			}
		}
	}
	std::cout << (long long) ans * (long long) (1 + (int)buffer.size()) % MOD << std::endl;
}