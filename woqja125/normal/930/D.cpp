#include<cstdio>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
struct P {
	int x, y;
	bool operator<(const P &A) const { return x < A.x; }
};
vector<P> a, b;
int min(const multiset<int> &X) {
	if (!X.empty()) return *X.begin();
	else return 1000000;
}
int max(const multiset<int> &X) {
	if (!X.empty()) return *X.rbegin();
	else return -1000000;
}
int get(const multiset<int> &a, const multiset<int> &b) {
	if (a.empty() || b.empty()) return 0;
	int l = max(min(a), min(b));
	int r = min(max(a), max(b));
	int re = r - l;
	return re > 0 ? re : 0;
}
long long solve(const vector<P> &in) {
	multiset<int> a, b;
	for (auto p : in) b.insert(p.y);
	int u=0;
	long long re = 0;
	for (int i = 0; i <= 200000; i++) {
		for (; u < in.size() && in[u].x <= i; u++) {
			b.erase(b.find(in[u].y));
			a.insert(in[u].y);
		}
		re += get(a, b);
	}
	return re;
}
int main() {
	int n;
	scanf("%d", &n);
	int x, y;
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &x, &y);
		x += 100000; y += 100000;
		if ((x+y)%2 == 0) {
			a.push_back({ (x + y) / 2, (x - y + 200000) / 2 });
		}
		else {
			b.push_back({ (x + y) / 2, (x - y + 200000) / 2 });
		}
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	printf("%lld\n", solve(a) + solve(b));
	return 0;
}