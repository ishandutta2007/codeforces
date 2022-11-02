#include<vector>
#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

#define left LEFT

const int N = 300;
int left[N];

int main() {
	string ans;
	int n;
	scanf("%d", &n);
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d", left + i);
		sum += left[i];
	}
	int pos = 0, dir = 0;
	while (sum > 0) {
		if (left[pos] > 0) {
			--left[pos];
			--sum;
			ans += 'P';
		}
		if (dir == 0) {
			if (pos == n - 1) {
				dir = 1;	
				--pos;
				ans += 'L';
			} else {
				++pos;
				ans += 'R';
			}
		} else {
			if (pos == 0) {
				dir = 0;
				++pos;
				ans += 'R';
			} else {
				--pos;
				ans += 'L';
			}
		}
	}
	printf("%s\n", ans.c_str());
	return 0;
}