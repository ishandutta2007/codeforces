#include <bits/stdc++.h>
using namespace std;

const int N = 75;

const int mod = 1e9 + 7;
const long long MOD = 1LL * mod * mod;

int k, len;
long long n, C[55][55];

struct Mat {
	int A[55][55];
	void init() {
		memset(A, 0, sizeof(A));
	}
}ind, T[N][N], pre[N][N], suf[N][N], start;

Mat operator * (Mat a, Mat b) {
	memset(C, 0, sizeof(C));		
	for(int i = 0; i <= len; ++ i) {
		for(int k = 0; k <= len; ++ k) {
			for(int j = 0;  j <= len; ++ j) {
				C[i][j] += 1LL * a.A[i][k] * b.A[k][j];
				if(C[i][j] >= MOD) C[i][j] -= MOD;
			}
		}
	}
	for(int i = 0; i <= len; ++ i) {
		for(int j = 0; j <= len; ++ j)
		ind.A[i][j] = C[i][j] % mod;
	}
	return ind;
}

namespace {
	int add(int x) {return (x >= mod) ? x - mod : x;}
	int sub(int x) {return (x < 0) ? x + mod : x;}
	void Add(int &x, int y) {x = add(x + y);}
	void Sub(int &x, int y) {x = sub(x - y);}
	int Mul(int x, int y) {return (1LL * x * y) % mod;}
	int Pow(int x, int y = mod - 2) {
		int res = 1;
		for(; y; y >>= 1, x = 1LL * x * x % mod) {
			if(y & 1) {
				res = 1LL * res * x % mod;
			}
		}
		return res;
	}
}

vector <int> calc(long long n, int k) {
	vector <int> ans;
	ans.clear();
	while(n) {
		ans.push_back(n % k);
		n /= k;
	}
	return ans;
}

void build(int x) {
	for(int i = 0; i < len; ++ i)  T[0][x].A[i][i] = 1;
	T[0][x].A[x][x] = 0;
	T[0][x].A[k + 1][x] = 1;
	T[0][x].A[x][k + 1] = mod - 1;
	T[0][x].A[k + 1][k + 1] = 2;
}

void make(int x) {
	pre[x][0] = T[x][0];
	for(int i = 1; i < k; ++ i) 
	pre[x][i] = pre[x][i - 1] * T[x][i];
	suf[x][k - 1] = T[x][k - 1];
	for(int i = k - 2; i >= 0; -- i)
	suf[x][i] = T[x][i] * suf[x][i + 1];
}

int main() {
	cin >> n >> k;
	-- n;
	vector <int> ex = calc(n, k);
	if(!ex.size()) ex.resize(1);
	len = k + 1;
	for(int i = 0; i < k; ++ i) build(i);
	start.init();
	start.A[0][k] = start.A[0][k + 1] = 1;
	for(int i = 1; i < (int) ex.size(); ++ i) {
		make(i - 1);
		for(int j = 0; j < k; ++ j) {
			if(j == 0) T[i][j] = pre[i - 1][k - 1];
			else
			T[i][j] = suf[i - 1][j] * pre[i - 1][(j + k - 1) % k];
		}
	}
	int bef = 0;
	for(int i = ex.size() - 1; i >= 0; -- i) {
		for(int j = 0; j < (int)ex[i] + (i == 0); ++ j) {
			start = start * T[i][(j + bef) % k];
		}
		bef += ex[i];
	}
	cout << start.A[0][k + 1] << endl;
}