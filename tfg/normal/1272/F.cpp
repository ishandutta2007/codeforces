#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cstring>
#include <queue>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 202;

std::string s, t;

struct State {
	State(int a = 0, int b = 0, int c = 0) {
		i = a, j = b, bal = c;
	}
	int i, j, bal;
	bool try_open() {
		bool got = bal + 1 < 2 * ms;
		if(i < (int) s.size() && s[i] == '(') {
			i++;
			//got = true;
		}
		if(j < (int) t.size() && t[j] == '(') {
			j++;
			//got = true;
		}
		bal++;
		return got;
	}

	bool try_closed() {
		bool got = bal > 0;
		if(i < (int) s.size() && s[i] != '(') {
			i++;
			//got = true;
		}
		if(j < (int) t.size() && t[j] != '(') {
			j++;
			//got = true;
		}
		bal--;
		return got;
	}
};

int dist[ms][ms][2*ms];
State st[ms][ms][2*ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::cin >> s >> t;
	memset(dist, 0x3f, sizeof dist);
	dist[0][0][0] = 0;
	std::queue<State> q;
	q.push(State(0, 0, 0));
	while(!q.empty()) {
		auto state = q.front();
		q.pop();
		if(state.i == (int) s.size() && state.j == (int) t.size() && state.bal == 0) {
			std::string str;
			while(state.i != 0 || state.j != 0 || state.bal != 0) {
				if(state.bal > st[state.i][state.j][state.bal].bal) {
					str = "(" + str;
				} else {
					str = ")" + str;
				}
				state = st[state.i][state.j][state.bal];
			}
			//str = "(" + str;
			std::cout << str << '\n';
			return 0;
		}
		int curDist = dist[state.i][state.j][state.bal];
		{
			auto nxt = state;
			if(nxt.try_open()) {
				if(dist[nxt.i][nxt.j][nxt.bal] > 1 + curDist) {
					dist[nxt.i][nxt.j][nxt.bal] = 1 + curDist;
					st[nxt.i][nxt.j][nxt.bal] = state;
					q.push(nxt);
				}
			}
		}
		{
			auto nxt = state;
			if(nxt.try_closed()) {
				if(dist[nxt.i][nxt.j][nxt.bal] > 1 + curDist) {
					dist[nxt.i][nxt.j][nxt.bal] = 1 + curDist;
					st[nxt.i][nxt.j][nxt.bal] = state;
					q.push(nxt);
				}
			}
		}
	}
}