#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
int k = 0;
int cm = 1;
struct P {
	int m[11], M[11];
	int c;
	P(int t=0, int C=1) {
		for (int i = 1; i <= k; i++) m[i] = M[i] = t;
		c = C;
	}
	bool operator<(const P &A) const {
		if(cm > 0) return m[cm] < A.m[cm];
		else return M[-cm] < A.M[-cm];
	}
};
set<P> S;
int t = -1;
int main() {
	int n;
	scanf("%d%d", &n, &k);
	S.emplace(0, 0);
	S.emplace(1000000010, 0);
	for (int i = 1; i <= n; i++) {
		P x;
		for (int j = 1; j <= k; j++) {
			scanf("%d", &x.m[j]);
			x.M[j] = x.m[j];
		}

		int m = 1000000010, M = -1;
		for (int j = 1; j <= k; j++) {
			cm = -j;
			auto it = S.lower_bound(x);
			m = min(m, it->m[1]);
			
			cm = j;
			it = S.lower_bound(x);
			M = max(M, it->m[1]);
		}

		cm = 1;
		auto its = S.lower_bound(m);
		auto ite = S.lower_bound(M);
		for (auto it = its; it != S.end() && it != ite; it++) {
			x.c += it->c;
			for (int j = 1; j <= k; j++) {
				x.M[j] = max(x.M[j], it->M[j]);
				x.m[j] = min(x.m[j], it->m[j]);
			}
		}
		S.erase(its, ite);

		S.insert(x);
		auto end = S.end(); end--; end--;
		printf("%d\n", end->c);
	}
	return 0;
}