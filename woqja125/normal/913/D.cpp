#include<queue>
#include<cstdio>
#include<algorithm>
using namespace std;
struct prob {
	int a, t, i;
	prob(int _a, int _t, int _i) :a(_a), t(_t), i(_i) {}
	bool operator<(const prob &A) const {
		return a > A.a;
	}
};
vector<prob> p;

int main() {
	int n;
	long long T;
	scanf("%d%lld", &n, &T);
	for (int i = 1; i <= n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		p.emplace_back(a, b, i);
	}
	sort(p.begin(), p.end());
	auto it = p.begin();

	priority_queue<int> s;
	long long ts = 0;

	int maxp = 0;

	for (int i = n; i >= 0; i--) {
		for (; it != p.end() && it->a >= i; it++) {
			s.emplace(it->t);
			ts += it->t;
		}

		if (s.size() < i) continue;
		
		while (s.size() > i) {
			ts -= s.top();
			s.pop();
		}

		if (ts <= T) {
			maxp = i;
			break;
		}
	}

	vector<pair<int, int>> np;

	for (int i = 0; i < n; i++) if(p[i].a >= maxp) np.emplace_back(p[i].t, p[i].i);
	sort(np.begin(), np.end());

	printf("%d\n%d\n", maxp, maxp);
	for (int i = 0; i < maxp; i++) printf("%d ", np[i].second);

	return 0;
}