#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100005;
int n;
int a[N], tr[N];

int lowbit(const int i) {
	return i & -i;
}

int getmax(int pos) {
	int ret = 0;
	while (pos) {
		ret = max(ret, tr[pos]);
		pos -= lowbit(pos);
	}
	return ret;
}

void insert(int pos, int val) {
	while (pos <= n) {
		tr[pos] = max(tr[pos], val);
		pos += lowbit(pos);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
	}
	for (int i = 1; i <= n; ++i) {
		insert(a[i], getmax(a[i]) + 1);	
	}
	printf("%d\n", getmax(n));
	return 0;
}