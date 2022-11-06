#include<stdio.h>
#include<queue>
using namespace std;
int main() {
	int n, m, t;
	scanf("%d", &n);
	m = n;
	priority_queue<int> H;
	int cnt = 0;
	printf("1 ");
	for (int i = 1; i <= n; i++) {
		scanf("%d", &t);
		cnt++;
		H.push(t);
		while (!H.empty() && H.top() == m) {
			H.pop();
			m--;
			cnt--;
		}
		printf("%d ", cnt + 1);
	}
	return 0;
}