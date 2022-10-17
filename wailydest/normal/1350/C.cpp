#include <cstdio>
#include <vector>
using namespace std;

const int N = 200000;
int lp[N + 1];
vector<int> pr;
vector<vector<int> > pr_deg;
int pr_ind[N];

void get() 
{
	for (int i = 2; i <= N; ++i) {
		if (lp[i] == 0) {
			lp[i] = i;
			pr_ind[i] = pr.size();
			pr.push_back(i);
		}
		for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j) 
			lp[i * pr[j]] = pr[j];
	}
}

vector<int> a;

inline long long po(long long a, long long b) 
{
	long long res = 1;
	while (b) {
		if (b & 1) res *= a;
		a *= a;
		b >>= 1;
	}
	return res;
}

int main() 
{
	get();
	int n;
	scanf("%d", &n);
	a.resize(n);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	pr_deg.resize(pr.size(), vector<int>(19));
	for (int i = 0; i < n; ++i) {
		while (a[i] > 1) {
			int p = lp[a[i]];
			int deg = 0;
			while (a[i] > 1 && lp[a[i]] == p) {
				a[i] /= p;
				++deg;
			}
			++pr_deg[pr_ind[p]][deg];
		}
	}
	long long ans = 1;
	for (int i = 0; i < pr.size(); ++i) {
		for (int j = 18; j > 0; --j) {
			if (pr_deg[i][j] >= n - 1) {
				ans *= po(pr[i], j);
				break;
			}
			pr_deg[i][j - 1] += pr_deg[i][j];
		}
	}
	printf("%lld\n", ans);
	return 0;
}