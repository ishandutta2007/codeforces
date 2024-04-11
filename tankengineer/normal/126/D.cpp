#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const long long UB = 1000000000000000000ll;

long long solve(vector<int> &s) {
	long long f1 = 1, f0 = 0;
	for (int i = 0; i < (int)s.size(); ++i) {
		long long nf1 = f1 + f0, nf0 = f1 * ((s[i] - 1) / 2) + f0 * (s[i] / 2);
		f1 = nf1;
		f0 = nf0;
	}
	return f1 + f0;
}

int main() {
	vector<long long> fibs;
	fibs.push_back(1);
	fibs.push_back(2);
	while (fibs.back() < UB) {
		int s = fibs.size();
		fibs.push_back(fibs[s - 2] + fibs[s - 1]);
	}
	reverse(fibs.begin(), fibs.end());
	int t;
	scanf("%d", &t);
	while (t--) {
		long long n;
		scanf("%I64d", &n);
		int last = -1;
		vector<int> s;
		for (int i = 0; i < (int)fibs.size(); ++i) {
			if (n >= fibs[i]) {
				if (last != -1) {
					s.push_back(i - last);
				}
				last = i;
				n -= fibs[i];
			}
		}
		s.push_back(fibs.size() - last);
		reverse(s.begin(), s.end());
		printf("%I64d\n", solve(s));
	}
	return 0;
}