#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int N = 100005;
int n;
vector<double> stat[N];
double ans;

void init(const int i, const int cnt) {
	for (int j = 0; j < cnt; ++j) {
		stat[i].push_back((double)0);
	}
	stat[i].push_back(1);
	ans += stat[i][0];
}

void take(const int i) {
	ans -= stat[i][0];
	int cnt = stat[i].size();
	vector<double> tmp;
	for (int j = 0; j < cnt - 1; ++j) tmp.push_back((double)0);
	for (int j = 0; j < cnt; ++j) {
		if (j > 0) {
			tmp[j - 1] += stat[i][j] * j / (cnt - 1); 
		}
		if (j < cnt - 1) {
			tmp[j] += stat[i][j] * (1 -  (double)j / (cnt - 1)); 
		}
	}
	stat[i] = tmp;
	ans += stat[i][0];
}

void push(const int i) {
	stat[i].push_back((double)0);
}

int main() {
	int q, tp, tu, tv, tk;
	ans = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &tp);
		init(i, tp);
	}
	scanf("%d", &q);
	while (q--) {
		scanf("%d %d %d", &tu, &tv, &tk);
		for (int i = 1; i <= tk; ++i) take(tu);
		for (int i = 1; i <= tk; ++i) push(tv);
		printf("%.12lf\n", ans);
	}
	return 0;
}