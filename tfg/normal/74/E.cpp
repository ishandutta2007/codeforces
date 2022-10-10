#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <cassert>
#include <map>
#include <queue>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

struct State {
	int a[6][6];
	void U(int j) {
		for(int i = 0; i < 5; i++) {
			std::swap(a[i][j], a[i+1][j]);
		}
	}
	void D(int j) {
		for(int i = 0; i < 5; i++) {
			std::swap(a[5-i][j], a[5-i-1][j]);
		}
	}
	void R(int i) {
		for(int j = 0; j < 5; j++) {
			std::swap(a[i][5-j], a[i][5-j-1]);
		}
	}
	void L(int i) {
		for(int j = 0; j < 5; j++) {
			std::swap(a[i][j], a[i][j+1]);
		}
	}
	void sendUP(int i, int j) {
		R(i);
		D(j);
		L(i);
		U(j);
	}
	void sendUP2(int i, int j) {
		L(i);
		D(j);
		R(i);
		U(j);
	}
	bool operator < (const State &o) const {
		for(int i = 0; i < 6; i++) {
			for(int j = 0; j < 6; j++) {
				if(a[i][j] != o.a[i][j]) {
					return a[i][j] < o.a[i][j];
				}
			}
		}
		return false;
	}
};

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int a[6][6];
	{
		std::string mat[6];
		std::vector<std::pair<int, int>> ord;
		for(int i = 0; i < 6; i++) {
			std::cin >> mat[i];
			for(int j = 0; j < 6; j++) {
				ord.emplace_back('0' <= mat[i][j] && mat[i][j] <= '9' ? mat[i][j] - '0' : 10 + mat[i][j] - 'A', i * 6 + j);
			}
		}
		std::sort(ord.begin(), ord.end());
		for(int i = 0; i < 36; i++) {
			a[ord[i].second / 6][ord[i].second % 6] = i;
		}
	}
	std::vector<std::pair<char, int>> ans;
	auto U = [&](int j) {
		//std::cout << "U\n";
		for(int i = 0; i < 5; i++) {
			std::swap(a[i][j], a[i+1][j]);
		}
		ans.emplace_back('U', j);
	};
	auto D = [&](int j) {
		//std::cout << "D\n";
		for(int i = 0; i < 5; i++) {
			std::swap(a[5-i][j], a[5-i-1][j]);
		}
		ans.emplace_back('D', j);
	};
	auto R = [&](int i) {
		//std::cout << "R\n";
		for(int j = 0; j < 5; j++) {
			std::swap(a[i][5-j], a[i][5-j-1]);
		}
		ans.emplace_back('R', i);
	};
	auto L = [&](int i) {
		//std::cout << "L\n";
		for(int j = 0; j < 5; j++) {
			std::swap(a[i][j], a[i][j+1]);
		}
		ans.emplace_back('L', i);
	};
	auto sendUP = [&](int i, int j) {
		//std::cout << "UP1\n";
		R(i);
		D(j);
		L(i);
		U(j);
	};
	auto sendUP2 = [&](int i, int j) {
		//std::cout << "UP2\n";
		L(i);
		D(j);
		R(i);
		U(j);
	};
	for(int on = 0; on < 36; on++) {
		//std::cout << "at " << on << ":\n";
		for(int i = 0; i < 6; i++) {
			for(int j = 0; j < 6; j++) {
				//std::cout << a[i][j] / 10 << a[i][j] % 10 << (j == 5 ? '\n' : ' ');
			}
		}
		//std::cout << '\n';
		int x, y;
		auto getPos = [&](int val) {
			x = -1, y = -1;
			for(int i = 0; i < 6; i++) {
				for(int j = 0; j < 6; j++) {
					if(a[i][j] == val) {
						x = i, y = j;
					}
				}
			}
			assert(x != -1);
		};
		getPos(on);
		if(on + 6 < 36) {
			if(x * 6 + y == on) {
				continue;
			}
			//std::cout << "at " << x << ", " << y << std::endl;
			if(x == on / 6) {
				sendUP(x+1, y);
				getPos(on);
			}
			assert(x != on / 6);
			while(y != on % 6) {
				//std::cout << "at " << x << ", " << y << std::endl;
				R(x);
				getPos(on);
			}
			while(x != on / 6) {
				//std::cout << "at " << x << ", " << y << std::endl;
				sendUP(x, y);
				getPos(on);
			}
			//std::cout << "at " << x << ", " << y << std::endl;
		} else {
			assert(on + 6 == 36);
			std::map<State, std::pair<State, char>> bck;
			State curState, endState;
			for(int i = 0; i < 6; i++) {
				for(int j = 0; j < 6; j++) {
					curState.a[i][j] = a[i][j];
					endState.a[i][j] = i * 6 + j;
				}
			}
			bck[curState] = {curState, 'E'};
			std::queue<State> q;
			q.push(curState);
			while(!q.empty() && !bck.count(endState)) {
				curState = q.front();
				q.pop();
				auto cur = curState;
				// try R
				cur.R(5);
				if(!bck.count(cur)) {
					bck[cur] = {curState, 'R'};
					q.push(cur);
				}
				// try L
				cur = curState;
				cur.L(5);
				if(!bck.count(cur)) {
					bck[cur] = {curState, 'L'};
					q.push(cur);
				}
				// try up1
				cur = curState;
				cur.sendUP(5, 0);
				if(!bck.count(cur)) {
					bck[cur] = {curState, 'U'};
					q.push(cur);
				}
				// try up2
				cur = curState;
				cur.sendUP2(5, 0);
				if(!bck.count(cur)) {
					bck[cur] = {curState, 'u'};
					q.push(cur);
				}
			}
			assert(bck.count(endState));
			std::vector<char> wtf;
			for(curState = endState; bck[curState].second != 'E'; curState = bck[curState].first) {
				wtf.push_back(bck[curState].second);
			}
			std::reverse(wtf.begin(), wtf.end());
			for(auto ch : wtf) {
				if(ch == 'R') {
					R(5);
				} else if(ch == 'L') {
					L(5);
				} else if(ch == 'U') {
					sendUP(5, 0);
				} else if(ch == 'u') {
					sendUP2(5, 0);
				} else {
					assert(0);
				}
			}
			break;
		}
	}
	for(int i = 0; i < 6; i++) {
		for(int j = 0; j < 6; j++) {
			assert(a[i][j] == i * 6 + j);
		}
	}
	assert(ans.size() <= 10000);
	std::cout << ans.size() << std::endl;
	for(auto op : ans) {
		std::cout << op.first << op.second+1 << '\n';
	}
}