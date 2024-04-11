#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <cmath>
using namespace std;
namespace Input
{
	const int BUF = 65536;
	char buf[BUF + 1];
	char *head = buf, *tail = buf;
}
inline char inputchar()
{
	using namespace Input;
	if(head == tail)
		*(tail = (head = buf) + fread(buf, 1, BUF, stdin)) = 0;//, head == tail ? exit(0) : (void)0;
	return *head++;
}
inline void inputnum(int &ret)
{
	char ch = inputchar();
	while(ch < '0' || ch > '9')
		ch = inputchar();
	ret = ch - '0';
	ch = inputchar();
	while(ch >= '0' && ch <= '9')
	{
		ret = ret * 10 + ch - '0';
		ch = inputchar();
	}
}
inline void inputsigned(int &ret)
{
	ret = 0;
	char ch = inputchar();
	while((ch < '0' || ch > '9') && ch != '-')
		ch = inputchar();
	bool neg = false;
	if(ch == '-')
		neg = true, ch = inputchar();
	while(ch >= '0' && ch <= '9')
	{
		ret = ret * 10 + ch - '0';
		ch = inputchar();
	}
	if(neg)
		ret = -ret;
}
int n, a[202020];
int ans[202020];
void solve() {
	inputnum(n);
	for (int i = 1; i <= n; i++)
		inputnum(a[i]);
	if (n % 2 == 1) {
		printf("NO\n");
		return;
	}
	sort(a + 1, a + n + 1);
	int mxcnt = 1, st = 1;
	for (int i = 1; i <= n; i++) {
		if (i < n && a[i] == a[i + 1]) {
			int j = i;
			while (j < n && a[j] == a[j + 1])
				j++;
			int cnt = j - i + 1;
			if (cnt >= mxcnt) {
				mxcnt = cnt;
				st = i;
			}
			i = j;
		}
	}
	if (mxcnt > n / 2 || (mxcnt == n / 2 && st != 1 && st != n / 2 + 1)) {
		printf("NO\n");
		return;
	}
	printf("YES\n");
	for (int i = 1; i <= n / 2; i++) {
		printf("%d %d ", a[i], a[i + n / 2]);
	}
	/*int ed = st + mxcnt - 1;
	if (n - st + 1 >= n / 2) {
		ed = st + n / 2 - 1;
		for (int i = 0; i < n / 2; i++) {
			printf("%d ", a[st + i]);
			if (ed + 1 + i <= n)
				printf("%d ", a[ed + 1 + i]);
			else
				printf("%d ", a[ed + 1 + i - n]);
		}
	} else {
		st = ed - n / 2 + 1;
		for (int i = 0; i < n / 2; i--) {
			printf("%d ", a[ed - i]);
			if (st - 1 - i >= 1)
				printf("%d ", a[st - 1 - i]);
			else
				printf("%d ", a[st - 1 - i + n]);
		}
	}*/
	printf("\n");
}
int main() {
	int T;
	inputnum(T);
	for (int i = 1; i <= T; i++) {
		solve();
	}
	return 0;
}