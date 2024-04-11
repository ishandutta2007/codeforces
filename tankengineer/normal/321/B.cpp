#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
vector<int> def, atk, pot;

int grd1() {
	int ret = 0;
	int n = min(atk.size(), pot.size());
	for (int i = 1; i <= n; ++i) {
		vector<int> a, b;
		for (int j = 0; j < i; ++j) {
			a.push_back(atk[j]);
			b.push_back(pot[pot.size() - j - 1]);
		}
		int tmp = 0;
		for (int j = 0; j < i; ++j) {
			if (b[j] > a[j]) {
				tmp += b[j] - a[j];
			}
		}
		ret = max(ret, tmp);
	}
	return ret;
}

int grd2() {
	vector<int> a = atk, b = def, c = pot;
	int ret = 0;
	for (int i = 0; i < b.size(); ++i) {
		vector<int>::iterator it = upper_bound(c.begin(), c.end(), b[i]);
		if (it == c.end()) {
			return ret;
		}
		c.erase(it);
	}
	for (int i = 0; i < a.size(); ++i) {
		vector<int>::iterator it = lower_bound(c.begin(), c.end(), a[i]);
		if (it == c.end()) {
			return ret;
		}
		ret += *it - a[i];
		c.erase(it);
	}
	for (int i = 0; i < c.size(); ++i) {
		ret += c[i];
	}
	return ret;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		int str;
		char type[5];
		scanf("%s%d", type, &str);
		if (type[0] == 'D') {
			def.push_back(str);
		} else {
			atk.push_back(str);
		}
	}
	for (int i = 0; i < m; ++i) {
		int t1;
		scanf("%d", &t1);
		pot.push_back(t1);
	}
	sort(atk.begin(), atk.end());
	sort(def.begin(), def.end());
	sort(pot.begin(), pot.end());	
	printf("%d\n", max(grd1(), grd2()));
	return 0;
}