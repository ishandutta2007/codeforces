#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	deque<int> q;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int a;
		scanf("%d", &a);
		q.push_back(a);
	}
	int sum[2];
	memset(sum, 0, sizeof(sum));
	for (int i = 0; i < n; ++i) {
		int val = 0;
		if (q.back() > q.front()) {
			val = q.back();	
			q.pop_back();
		} else {
			val = q.front();
			q.pop_front();
		}
		sum[i & 1] += val;
	}
	printf("%d %d\n", sum[0], sum[1]);
	return 0;
}