#include <cstdio>
#include <vector>
#include <queue>

typedef long long Int;

using namespace std;

const Int INF = 1001001001001001001LL;

struct BIT {
	vector<int> p;
	int n;

	BIT(int n) : n(n) {
		p.resize(n + 1, 0);
	}

	void add(int x, int v) {
		while (x <= n) {
			p[x] += v;
			x += x & -x;
		}
	}

	int sum(int x) const {
		int s = 0;
		while (x > 0) {
			s += p[x];
			x -= x & -x;
		}
		return s;
	}
};

struct event {
	Int time;
	int from, to, id;
	event(Int t, int fr, int to, int i) : time(t), from(fr), to(to), id(i) { }
};
bool operator < (const event& e, const event& f)
{
	return e.time > f.time;
}

int n, m;

int wantstogo[100050];
Int sol[100050];
vector<int> dest[100050], src[100050];

int determine_next(const BIT& wait, const BIT& go, int cur_floor, Int cur_time, Int& next_t)
{
	if (src[cur_floor].size() > 0 || dest[cur_floor].size() > 0) {
		next_t = cur_time;
		return 0;
	}

	int p_down = wait.sum(cur_floor) + go.sum(cur_floor);
	int p_up = wait.sum(m) + go.sum(m) - p_down;

	int dir = 0;

	if (p_down == 0 && p_up == 0) {
		next_t = INF;
		return dir;
	}

	if (p_up >= p_down) {
		dir = 1;
		int dw = wait.sum(cur_floor) + go.sum(cur_floor);
		int lo = cur_floor, hi = m;
		while (hi - lo > 1) {
			int mid = (hi + lo) / 2;
			
			if (wait.sum(mid) + go.sum(mid) - dw > 0) {
				hi = mid;
			} else {
				lo = mid;
			}
		}
		next_t = cur_time + hi - cur_floor;
	} else {
		dir = -1;
		int dw = wait.sum(cur_floor) + go.sum(cur_floor);
		int lo = 0, hi = cur_floor - 1;
		while (hi - lo > 1) {
			int mid = (hi + lo) / 2;

			if (wait.sum(mid) + go.sum(mid) == dw) {
				hi = mid;
			} else {
				lo = mid;
			}
		}
		next_t = cur_time + cur_floor - hi;
	}

	return dir;
}

int main()
{
	scanf("%d%d", &n, &m);

	priority_queue<event> Q;
	Int next_t = INF;

	for (int i = 0; i < n; ++i) {
		int t, s, f;
		scanf("%d%d%d", &t, &s, &f);
		wantstogo[i] = f;
		Q.push(event(t, s, f, i));
	}

	BIT wait(m), go(m);

	int cur_floor = 1, cur_dir = 0;
	Int cur_time = 0;

	while (!Q.empty() || next_t < INF) {
		if (Q.empty() || next_t <= Q.top().time) {
			cur_floor += (next_t - cur_time) * cur_dir;
			for (int i = 0; i < (int)dest[cur_floor].size(); ++i) {
				sol[dest[cur_floor][i]] = next_t;
			}
			go.add(cur_floor, -dest[cur_floor].size());
			dest[cur_floor].clear();
			for (int i = 0; i < (int)src[cur_floor].size(); ++i) {
				dest[wantstogo[src[cur_floor][i]]].push_back(src[cur_floor][i]);
				go.add(wantstogo[src[cur_floor][i]], 1);
			}
			wait.add(cur_floor, -src[cur_floor].size());
			src[cur_floor].clear();
			cur_time = next_t;
			cur_dir = determine_next(wait, go, cur_floor, cur_time, next_t);
		} else {
			event e = Q.top();
			Q.pop();

			cur_floor += (e.time - cur_time) * cur_dir;
			wait.add(e.from, 1);
			src[e.from].push_back(e.id);
			cur_time = e.time;
			cur_dir = determine_next(wait, go, cur_floor, cur_time, next_t);
		}
	}

	for (int i = 0; i < n; ++i) {
		printf("%I64d\n", sol[i]);
	}

	return 0;
}