#include <cstdio>
#include <unordered_map>

int t, n;
std::unordered_map<int, int> mp;
bool ok;

const int X = 1242134321;

void run(long long w) {
	if (w < ~(1 << 31) && mp.count(w ^ X) && mp[w ^ X]) --mp[w ^ X];
	else {
		if (w == 1) ok = 0;
		else {
			run(w >> 1);
			if (ok) run(w + 1 >> 1);
		}
	}
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		long long s = 0;
		for (int i = 0; i < n; ++i) {
			int x;
			scanf("%d", &x);
			++mp[x ^ X];
			s += x;
		}
		ok = 1;
		run(s);
		printf("%s\n", ok ? "YES" : "NO");
		mp.clear();
	}
	return 0;
}