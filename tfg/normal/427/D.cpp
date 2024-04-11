#include <iostream>
#include <vector>

const int ms = 5050;

int c;
std::vector<int> pos[2][2 * ms][2];
int to[26];
int step[26];
int cur_step = 0;

int main() {
	std::ios_base::sync_with_stdio(false);std::cin.tie(NULL);
	std::string str[2];
	std::cin >> str[0] >> str[1];
	int c = 1;
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < str[i].size(); j++) {
			pos[0][0][i].push_back(j);
		}
	}
	for(int i = 0; c > 0; i++) {
		//std::cout << "----------------\nlen is now " << i << std::endl;
		int lastc = c;
		c = 0;
		for(int j = 0; j < lastc; j++) {
			cur_step++;
			if(std::min(pos[0][j][0].size(), pos[0][j][1].size()) == 0) {
				pos[0][j][0].clear();
				pos[0][j][1].clear();
				continue;
			} else if(pos[0][j][0].size() + pos[0][j][1].size() == 2 && i > 0) {
				std::cout << i << std::endl;
				return 0;
			}
			for(int k = 0; k < 2; k++) {
				while(!pos[0][j][k].empty()) {
					int p = pos[0][j][k].back();
					//std::cout << "got pos (" << k << ", " << p << ") on " << j << std::endl;
					pos[0][j][k].pop_back();
					if(p + i >= str[k].size()) {
						continue;
					}
					if(step[str[k][p+i] - 'a'] != cur_step) {
						step[str[k][p+i] - 'a'] = cur_step;
						to[str[k][p+i] - 'a'] = c++;
					}
					pos[1][to[str[k][p+i] - 'a']][k].push_back(p);
					//std::cout << "going to " << to[str[k][p+i] - 'a'] << " using " << str[k][p+i] << std::endl;
				}
			}
		}
		std::swap(pos[0], pos[1]);
	}
	std::cout << "-1\n"; 
}