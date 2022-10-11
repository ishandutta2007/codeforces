#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <utility>
#include <queue>
#include <cstdio>

struct State {
	int f[5];

	void read() {
		for(int i = 0; i < 5; i++) {
			f[i] = 0;
		}
		for(int i = 0; i < 8; i++) {
			int t;
			scanf("%i", &t);
			f[t]++;
		}
	}

	void print() {
		std::cout << "(";
		for(int i = 0; i < 5; i++) {
			std::cout << f[i] << (i + 1 == 5 ? ')' : ' ');
		}
	}

	std::set<std::pair<State, State> > gen(State a) {
		std::set<std::pair<State, State> > ans;
		if(a.f[0] != 0) {
			for(int i = 1; i < 5; i++) {
				if(f[i]) {
					a.f[5 - i]++;
					a.f[0]--;
					ans.insert({a, *this});
					a.f[5 - i]--;
					a.f[0]++;
				}
			}
		}
		for(int i = 1; i < 5; i++) {
			for(int j = 1; j < 5; j++) {
				if((j - i + 5) % 5 != 0 && f[i] && a.f[j]) {
					a.f[j]--;
					a.f[(j - i + 5) % 5]++;
					ans.insert({a, *this});
					a.f[j]++;
					a.f[(j - i + 5) % 5]--;
				}
			}
		}
		return ans;
	}

	std::vector<std::pair<State, State> > gen2(State a) {
		std::vector<std::pair<State, State> > ans;
		for(int i = 1; i < 5; i++) {
			for(int j = 1; j < 5; j++) {
				if((i + j) % 5 != 0 && f[i] && a.f[j]) {
					f[i]--;
					f[(i + j) % 5]++;
					ans.emplace_back(a, *this);
					f[i]++;
					f[(i + j) % 5]--;
				}
			}
		}
		return ans;
	}

	
};

bool operator < (State a, State b) {
	int i = 0;
	while(i < 5 && a.f[i] == b.f[i]) i++;
	return i < 5 && a.f[i] < b.f[i];
}

State cur_state;
std::vector<State> states;
std::map<std::pair<State, State>, int> result, degree;

long long gen(int on, int f) {
	if(on == 5) {
		if(f == 0) {

			states.push_back(cur_state);
			return 1;
		} else {
			return 0;
		}
	}
	long long ans = 0;
	for(int i = 0; i <= f; i++) {
		cur_state.f[on] = i;
		ans += gen(on + 1, f - i);
	}
	return ans;
}

int main() {
	/*State hmm;
	hmm.f[0] = 8;
	hmm.f[1] = hmm.f[2] = hmm.f[3] = hmm.f[4] = 0;
	State hmmm;
	hmmm.f[4] = 1;
	hmmm.f[0] = 6;
	hmmm.f[1] = hmmm.f[2] = hmmm.f[3] = 0;
	hmmm.f[2] = 1;
	auto wtf = hmmm.gen(hmm);
	for(auto v : wtf) {v.first.print();std::cout << ", ";v.second.print();std::cout << '\n';}
	std::cout << gen(0, 8) << '\n';*/
	gen(0, 8);
	std::queue<std::pair<State, State> > q;
	for(auto a : states) {
		for(auto b : states) {
			auto v = a.gen(b);
			for(auto c : v) {
				degree[c]++;
			}
			if(std::max(a.f[0], b.f[0]) == 8 && a.f[0] + b.f[0] != 16) {
				q.push({a, b});
				result[{a, b}] = -1;
			}
		}
	}
	int cnt = 0;
	while(!q.empty() && cnt++ < 1e8) {
		auto a = q.front();
		q.pop();
		int cur_r = result[a];
		//if(1)
		//	{std::cout << "on states ";a.first.print();std::cout << ", ";a.second.print();std::cout << " result is " << cur_r << "\n";}
		//continue;
		auto v = a.first.gen(a.second);
		for(auto b : v) {
			//std::cout << "can go to state ";b.first.print(); std::cout << ", ";b.second.print(); std::cout << "\n";
			if(result.count(b)) {
				continue;
			}
			degree[b]--;
			if(cur_r == -1) {
				result[b] = 1;
				q.push(b);
			} else if(degree[b] == 0) {
				q.push(b);
				result[b] = -1;
			}
		}
	}
	//std::cout << result.size() << '\n';
	int n;
	std::cin >> n;
	while(n--) {
		int f;
		std::cin >> f;
		std::pair<State, State> a;
		a.first.read();
		a.second.read();
		if(f == 1) {
			std::swap(a.first, a.second);
		}
		int r = result[a];
		if(r == 0) {
			std::cout << "Deal\n";
		} else if(r == 1 && f == 0) {
			std::cout << "Alice\n";
		} else if(r == -1 && f == 0) {
			std::cout << "Bob\n";
		} else if(r == -1 && f == 1) {
			std::cout << "Alice\n";
		} else if(r == 1 && f == 1) {
			std::cout << "Bob\n";
		} 
	}
}