#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int n;
int m[100], c[100][100];

int main() {
	scanf("%d", &n);
	vector<int> v;
	int sum1 = 0, sum2 = 0;	
	for (int i = 0; i < n; ++i) {
		scanf("%d", m + i);
		for (int j = 0; j < m[i]; ++j) {
			scanf("%d", &c[i][j]);
			if (m[i] % 2 == 0) {
				if (j < m[i] / 2) {
					sum1 += c[i][j];
				} else {
					sum2 += c[i][j];
				}
			} else {
				if (j < m[i] / 2) {
					sum1 += c[i][j];
				} else if (j > m[i] / 2) {
					sum2 += c[i][j];
				} else {
					v.push_back(c[i][j]);
				}
			}
		}
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	for (int i = 0; i < (int)v.size(); ++i) {
		if (~i & 1) {
			sum1 += v[i];
		} else {
			sum2 += v[i];
		}
	}
	printf("%d %d\n", sum1, sum2);
	return 0;
}