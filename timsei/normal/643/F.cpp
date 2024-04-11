#include <bits/stdc++.h>
using namespace std;

#define T unsigned int

const T N = 4e6 + 5;
const T MAX = 1024 * 16;
const T L = 135;

T n, m, x, y, p, q;
T dp[MAX + 10][L];

struct Mat {
	T A[L][L];
	
	void init(void) {
		memset(A, 0, sizeof(A));
	}
	
	friend Mat operator * (Mat a, Mat b) {
		Mat c;
		c.init();
		for(T k = 0; k <= p; ++ k) {
			for(T i = 0; i <= k; ++ i) {
				for(T j = k; j <= p; ++ j) {
					c.A[i][j] += a.A[i][k] * b.A[k][j];
				}
			}
		}
		return c;
	}
}All[N / MAX + 10], Base;

T CCC[L][L];

T gcd(T x, T y) {
	return (!y) ? x : gcd(y, x % y);
}

T C(T x, T y) {
	vector <T> A;
	A.clear();
	for(T i = 1; i <= y; ++ i) A.push_back(x - i + 1);
	for(T i = 1; i <= y; ++ i) {
		T now = i;
		for(T j = 0; j < (T) A.size(); ++ j) {
			T G = gcd(now, A[j]);
			A[j] /= G;
			now /= G;
		}
	}
	T ans = 1;
	for(T i = 0; i < (T) A.size(); ++ i)
	ans = ans * A[i];
	return ans;
}

int main(void) {
	cin >> n >> p >> q;
	p = min(p, n - 1);
	Base.init();
	for(T i = 0; i <= p; ++ i) {
		for(T j = 0; j <= i; ++ j) {
			CCC[i - j][i] = Base.A[i - j][i] = C(n - p + i, j);
		}
	}
	for(T i = 1; i < MAX; i <<= 1) {
		Base = Base * Base;
	}
	All[0].init();
	for(T i = 0; i <= p; ++ i) All[0].A[i][i] = 1;
	All[1] = Base;
	for(T i = 2; i <= q / MAX; ++ i)
	All[i] = All[1] * All[i - 1];
	for(T i = 0; i <= p; ++ i) dp[0][i] = 1;
	
	for(T i = 1; i < MAX; ++ i) {
		for(T a = 0; a <= p; ++ a) {
			for(T b = a; b <= p; ++ b) {
				dp[i][b] += dp[i - 1][a] * CCC[a][b];
			}
		}
	}
	
	T ans = 0, a, b, it;
	a = 0, b = 0;
	for(T i = 1; i <= q; ++ i) {
		++ b;
		if(b == MAX) ++ a, b = 0;
		it = 0;
		for(T beds = 0; beds <= p; ++ beds) {
			it += dp[b][beds] * All[a].A[beds][p];
		}
		ans ^= it * i;
	}
	cout << ans << endl;
}