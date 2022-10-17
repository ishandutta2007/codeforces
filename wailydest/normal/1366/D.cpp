#include <cstdio>
#include <vector>
using namespace std;

const int A = 10000000;
int lp[A + 1];
vector<int> p;

void p_init() 
{
	for (int i = 2; i <= A; ++i) {
		if (!lp[i]) {
			p.push_back(i);
			lp[i] = i;
		}
		for (int j = 0; j < (int)p.size() && p[j] <= lp[i] && i * p[j] <= A; ++j) lp[i * p[j]] = p[j];
	}
}

const int N = 500000;
pair<int, int> ans[N];

void single(int v, int &a1, int &a2) 
{
	a1 = a2 = -1;
	int d = lp[v];
	int res = 1;
	if (d == v) return;
	do {
		v /= d;
		res *= d;
	} while (lp[v] == d);
	if (v == 1) return;
	a1 = res;
	a2 = v;
}

int main() 
{
	p_init();
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int v;
		scanf("%d", &v);
		single(v, ans[i].first, ans[i].second);
	}
	for (int i = 0; i < n; ++i) printf("%d ", ans[i].first);
	printf("\n");
	for (int i = 0; i < n; ++i) printf("%d ", ans[i].second);
	printf("\n");
	return 0;
}