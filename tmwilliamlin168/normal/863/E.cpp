#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }

int main() {
	int n;
	while (~scanf("%d", &n)) {
		vector<int> L(n);
		vector<int> R(n);
		for (int i = 0; i < n; ++ i)
			scanf("%d%d", &L[i], &R[i]), -- L[i];
		vector<int> values;
		rep(i, n) {
			values.push_back(L[i]);
			values.push_back(R[i]);
		}
		sort(values.begin(), values.end());
		values.erase(unique(values.begin(), values.end()), values.end());
		int X = (int)values.size();
		vector<int> add(X + 1);
		rep(i, n) {
			int l = (int)(lower_bound(values.begin(), values.end(), L[i]) - values.begin());
			int r = (int)(lower_bound(values.begin(), values.end(), R[i]) - values.begin());
			++ add[l], -- add[r];
		}
		rep(i, X)
			add[i + 1] += add[i];
		vector<int> sum(X + 1);
		rep(i, X)
			sum[i + 1] = sum[i] + (add[i] >= 2);
		int ans = -1;
		rep(i, n) {
			int l = (int)(lower_bound(values.begin(), values.end(), L[i]) - values.begin());
			int r = (int)(lower_bound(values.begin(), values.end(), R[i]) - values.begin());
			if (sum[r] - sum[l] == r - l) {
				ans = i;
				break;
			}
		}
		printf("%d\n", ans == -1 ? ans : ans + 1);
	}
	return 0;
}