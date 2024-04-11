#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>
#include <set>
#include <queue>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 200200;

int a[ms];
bool dead[ms];
std::string str;

struct Event {
	int i, j;
	Event(int a = -1, int b = -1) { i = a, j = b; }
	bool operator > (const Event &o) const {
		return std::pair<int, int>(abs(a[i] - a[j]), std::min(i, j)) > std::pair<int, int>(abs(a[o.i] - a[o.j]), std::min(o.i, o.j));
	}
};

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::cin >> str;
	std::set<int> alive;
	for(int i = 0; i < n; i++) {
		alive.insert(i);
		std::cin >> a[i];
	}
	std::priority_queue<Event, std::vector<Event>, std::greater<Event> > hp;
	for(int i = 0; i+1 < n; i++) {
		if(str[i] != str[i+1]) {
			hp.push(Event(i, i+1));
		}
	}
	std::vector<std::pair<int, int>> ans;
	while(!hp.empty()) {
		auto event = hp.top();
		hp.pop();
		if(dead[event.i] || dead[event.j]) continue;
		dead[event.i] = dead[event.j] = true;
		int i = event.i, j = event.j;
		alive.erase(i);
		alive.erase(j);
		auto itr = alive.lower_bound(j);
		auto itl = itr;
		if(itr != alive.end() && itr != alive.begin()) {
			itl--;
			if(str[*itl] != str[*itr]) {
				hp.push(Event(*itl, *itr));
			}
		}
		ans.emplace_back(i+1, j+1);
	}
	std::cout << ans.size() << '\n';
	for(auto wtf : ans) std::cout << wtf.first << ' ' << wtf.second << '\n';
}