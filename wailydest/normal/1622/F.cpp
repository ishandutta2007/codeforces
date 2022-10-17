#include <cstdio>
#include <set>
#include <cstring>
#include <chrono>
#include <algorithm>
#include <vector>
#include <random>

const int N = 1000005;
int n, lp[N], in[N], u[N];
unsigned long long pr[N], ex[N];
std::set<std::pair<long long, int> > st;
std::vector<int> p;
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

int main() 
{
	scanf("%d", &n);
	memset(lp, -1, N << 2);
	for (int i = 2; i <= n; ++i) {
		if (lp[i] == -1) {
			pr[p.size()] = rng();
			lp[i] = p.size();
			p.push_back(i);
		}
		for (int j = 0; j < (int)p.size() && j <= lp[i] && p[j] * i < N; ++j) lp[p[j] * i] = j;
	}
	unsigned long long cur = 0, ov = 0;
	for (int i = 1; i <= n; ++i) {
		int val = i;
		while (val > 1) {
			int t = lp[val];
			do {
				cur ^= pr[t];
				val /= p[t];
			} while (!(val % p[t]));
		}
		st.insert(std::make_pair(cur, i));
		ov ^= cur;
		ex[i] = cur;
	}
	std::set<std::pair<long long, int> >::iterator it, it1;
	if (ov) {
		if ((it = st.lower_bound(std::make_pair(ov, 0))) != st.end() && it->first == ov) u[it->second] = 1;
		else {
			bool ok = 0, fi = 0;
			int i = n;
			while (!ok) {
				if (fi) st.erase(std::make_pair(ex[i], i));
				for (it = st.begin(); it != st.end() && !ok; ++it) {
					it1 = st.lower_bound(std::make_pair(ov ^ it->first ^ (fi ? ex[i] : 0), 0));
					if (it1 == it) ++it1;
					if (it1 != st.end() && it1->first == (ov ^ it->first ^ (fi ? ex[i] : 0))) {
						ok = 1;
						u[it->second] = 1;
						u[it1->second] = 1;
						if (fi) u[i] = 1;
					}
				}
				if (fi) st.insert(std::make_pair(ex[i], i));
				if (fi) --i;
				fi = 1;
			}
		}
	}
	int ans = n;
	for (int i = 1; i <= n; ++i) ans -= u[i];
	printf("%d\n", ans);
	for (int i = 1; i <= n; ++i) if (!u[i]) printf("%d ", i);
	printf("\n");
	return 0;
}