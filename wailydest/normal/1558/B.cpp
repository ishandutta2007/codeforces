#include <cstdio>
#include <vector>

int md;

inline int add(int a, int b) 
{
	a += b;
	if (a >= md) a -= md;
	return a;
}
inline int sub(int a, int b) 
{
	a -= b;
	if (a < 0) a += md;
	return a;
}

const int N = 4000005;
int n, l[N], d[N], sum, cur;
std::vector<int> p;
std::vector<std::pair<int, int> > di;

void run(int val, int x, int ind) 
{
	if (ind == di.size()) {
		if (x == val) return;
		cur = add(cur, sub(d[x], d[x - 1]));
		return;
	}
	for (int i = 0, cur = x; i <= di[ind].second; ++i) {
		run(val, cur, ind + 1);
		if (i != di[ind].second) cur *= di[ind].first;
	}
}

int main() 
{
	for (int i = 2; i < N; ++i) {
		if (!l[i]) {
			l[i] = i;
			p.push_back(i);
		}
		for (int j = 0; j < (int)p.size() && p[j] <= l[i] && p[j] * i < N; ++j) l[p[j] * i] = p[j];
	}
	scanf("%d%d", &n, &md);
	d[1] = 1;
	sum = 1;
	for (int i = 2; i <= n; ++i) {
		int x = i;
		di.clear();
		while (x > 1) {
			di.push_back(std::make_pair(l[x], 0));
			do {
				++di.back().second;
				x /= di.back().first;
			} while (!(x % di.back().first));
		}
		run(i, 1, 0);
		d[i] = add(sum, cur);
		sum = add(sum, d[i]);
	}
	printf("%d\n", d[n]);
	return 0;
}