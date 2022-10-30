#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	vector<long long> v;
	int n;
	scanf("%d", &n);
	long long anst = 0, anst1 = 0, ansr = n;
	for (int i = 1; i <= n; ++i) {
		int t1;
		scanf("%d", &t1);
		v.push_back(t1);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; ++i) {
		long long ai = v[i];
		anst1 += ai;
		anst += ai * (2 * (i + 1) - n);
	}
	anst *= 2;
	anst -= anst1;
	long long r = __gcd(anst, ansr);
	cout << anst / r << ' ' << ansr / r << endl;
	return 0;
}