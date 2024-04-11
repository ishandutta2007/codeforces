#include <bits/stdc++.h>
using namespace std;

const int mxN=5e5, mxK=100;
int n, k, p, ps[mxN+1], dp[2][mxN+1];

struct ftree {
	int a[mxK+1];
	inline void rst() {
		memset(a, 69, sizeof(a));
	}
	inline void upd(int i, int x) {
		for(++i; i<=p; i+=i&-i)
			a[i]=min(x, a[i]);
	}
	inline int qry(int i) {
		int r=INT_MAX;
		for(; i; i-=i&-i)
			r=min(a[i], r);
		return r;
	}
} ft1;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k >> p;
	for(int i=0; i<n; ++i) {
		int ai;
		cin >> ai;
		ps[i+1]=(ps[i]+ai)%p;
	}
	for(int i=1; i<=k; ++i) {
		ft1.rst();
		memset(dp[i&1], 0, sizeof(dp[i&1]));
		ft1.upd(ps[i-1], dp[i&1^1][i-1]-ps[i-1]);
		int m2=dp[i&1^1][i-1]-ps[i-1];
		for(int j=i; j<=n; ++j) {
			dp[i&1][j]=min(ft1.qry(ps[j]+1), m2+p)+ps[j];
			if(i>1) {
				ft1.upd(ps[j], dp[i&1^1][j]-ps[j]);
				m2=min(dp[i&1^1][j]-ps[j], m2);
			}
		}
	}
	cout << dp[k&1][n];
}