#include<cstdio>
#include<string>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const long long MOD = 1000000007;

vector<string> fiboString;

void prepare(const int maxl) {
	fiboString.push_back("a");
	fiboString.push_back("b");
	while (fiboString[fiboString.size() - 2].size() < maxl) {
		fiboString.push_back(fiboString.back() + fiboString[fiboString.size() - 2]);
	}
}

struct Matrix {
	long long data[4][4];

	Matrix(const int num = 0) {
		memset(data, 0, sizeof(data));
		if (num == 1) {
			for (int i = 0; i < 4; ++i) {
				data[i][i] = 1;
			}
		} else if (num > 1) {
			data[0][0] = 0; data[0][1] = 1;
			data[1][0] = 1; data[1][1] = 1;
			data[1][num] = 1;
			data[2][2] = data[3][3] = 1;
		}
	}

	long long * operator[] (const int i) {
		return data[i];
	}
};

Matrix operator * (Matrix a, Matrix b) {
	Matrix ret;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			for (int k = 0; k < 4; ++k) {
				(ret[i][j] += a[i][k] * b[k][j]) %= MOD;
			}
		}
	}
	return ret;
}

Matrix multiply(const Matrix a, const long long n) {
	Matrix ret(1);
	for (int i = 60; i >= 0; --i) {
		ret = ret * ret;
		if (n >> i & 1) {
			ret = ret * a;
		}
	}
	return ret;
}

Matrix step(const long long n) {
	Matrix odd(2), even(3), mul = even * odd,
		   ret = multiply(mul, n >> 1);
	if (n & 1) {
		ret = odd * ret;
	}
	return ret;
}

int KMP(const string s, string p) {
	p = p + ' ';
	int l1 = s.size(), l2 = p.size();
	vector<int> next;
	next.push_back(-1);
	for (int i = 1; i < l2; ++i) {
		next.push_back(next.back());
		while (next.back() != -1 && p[next.back()] != p[i - 1]) {
			next.back() = next[next.back()];
		}
		++next.back();
	}
	int ret = 0, t = 0;
	for (int i = 0; i < l1; ++i) {
		while (t != -1 && s[i] != p[t]) {
			t = next[t];
		}
		++t;
		if (t == l2 - 1) {
			++ret;
		}
	}
	return ret;
}

long long solve(const long long n, const string s) {
	if (n < fiboString.size()) {
		return KMP(fiboString[n], s);
	}
	int pt = 0;
	while (fiboString[pt].size() < s.size()) {
		++pt;
	}
	string sFormer = fiboString[pt], sLatter = fiboString[pt + 1];
	long long cntFormer = KMP(sFormer, s), cntLatter = KMP(sLatter, s),
			  cntFormerLatter = KMP(sFormer.substr(sFormer.size() - s.size() + 1, s.size() - 1) + sLatter.substr(0, s.size() - 1), s),
			  cntLatterFormer = KMP(sLatter.substr(sLatter.size() - s.size() + 1, s.size() - 1) + sFormer.substr(0, s.size() - 1), s);
	Matrix met = step(n - pt);
	return (cntFormer * met[0][0] + cntLatter * met[0][1] + cntLatterFormer * met[0][2] + cntFormerLatter * met[0][3]) % MOD;	
}

int main() {
	ios::sync_with_stdio(false);
	long long k;
	int m;
	cin >> k >> m;
	--k;
	int maxlen = 0;
	vector<string> queries;
	for (int i = 0; i < m; ++i) {
		string tmp;
		cin >> tmp;
		queries.push_back(tmp);
		maxlen = max(maxlen, (int)tmp.size());
	}
	prepare(maxlen);
	for (int i = 0; i < m; ++i) {
		cout << solve(k, queries[i]) << endl;
	}
	return 0;
}