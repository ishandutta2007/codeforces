#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <set>
#include <queue>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const long long INF = 1e18;

int n, m;

struct Frog {
	int id;
	int ori;
	long long pos, t, jump;
	void read() {
		std::cin >> ori >> jump;
		ori--;
		pos = (ori+jump) % m;
		t = 0;
	}
	void move(long long curT) {
		pos = posAt(curT, n);
		t = curT;
	}
	long long posAt(long long curT, int curId = -1) const { return (pos + (curT - (curId < id) - t + m) * jump) % m; };
	std::pair<long long, int> catchUp(const Frog &o) const {
		if(id == o.id) return std::pair<long long, int>(INF, id);
		long long curT = std::max(t, o.t);
		long long vals[2][2];
		vals[0][0] = posAt(curT, id-1);
		vals[0][1] = jump;
		vals[1][0] = o.posAt(curT, id-1);
		vals[1][1] = o.jump;
		long long dist = (vals[1][0] - vals[0][0] + m) % m;
		//std::cout << "distance is " << dist << ", jumps (" << jump << ", " << o.jump << "), ids (" << id << ", " << o.id << ")\n";
		if(dist <= jump) {
			return std::pair<long long, int>(curT, id);
		} else {
			return std::pair<long long, int>(jump > o.jump ? (dist - o.jump - 1) / (jump - o.jump) + curT : INF, id);
		}
	}
	bool operator < (const Frog &o) const { return ori != o.ori ? ori < o.ori : t < o.t; };
};

struct Event {
	Event() {}
	Event(Frog a, Frog b) : s(a), t(b) { cost = a.catchUp(b); }
	Frog s, t;
	std::pair<long long, int> cost;
	bool operator < (const Event &o) const { return cost > o.cost; }
};

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::cin >> n >> m;
	std::set<Frog> st;
	for(int i = 0; i < n; i++) {
		Frog cur;
		cur.read();
		cur.id = i;
		st.insert(cur);
	}
	std::priority_queue<Event> hp;
	Frog last = *st.rbegin();
	for(auto it : st) {
		hp.push(Event(last, it));
		last = it;
	}
	int cnt = 0;
	while(!hp.empty()) {
		//if((cnt++) >= 10) break;
		Event cur = hp.top();
		hp.pop();
		//std::cout << "popping (" << cur.cost.first << ", " << cur.cost.second << ")\n";
		if(cur.cost.first >= INF || !st.count(cur.s) || !st.count(cur.t)) continue;
		auto s = cur.s;
		long long curT = cur.cost.first;
		s.move(curT);
		long long r = s.pos;
		long long l = r - s.jump;
		int got = 0;
		while((int) st.size() > 1) {
			auto it = st.upper_bound(cur.s);
			if(it == st.end()) {
				it = st.begin();
				assert(it != st.end());
			}
			long long other = it->posAt(curT, s.id) + m;
			while(other > r) {
				other -= m;
			}
			if(l <= other && other <= r) {
				//std::cout << "frog " << s.id << " killing " << it->id << " at time " << curT << '\n';
				st.erase(it);
				got++;
			} else {
				break;
			}
		}
		//s.move(curT + 1);
		s.jump -= got;
		//std::cout << s.id << " at pos " << s.pos << " on time " << s.t << '\n';
		st.erase(cur.s);
		st.insert(s);
		auto it = st.upper_bound(s);
		if(it == st.end()) {
			it = st.begin();
		}
		hp.push(Event(s, *it));
		it = st.lower_bound(s);
		if(it == st.begin()) {
			it = st.end();
		}
		it--;
		hp.push(Event(*it, s));
	}
	std::cout << st.size() << '\n';
	for(auto it : st) std::cout << it.id+1 << '\n';
}