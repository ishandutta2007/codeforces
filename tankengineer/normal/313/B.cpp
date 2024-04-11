#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 200005;

char s[N];
int num[N], n, m, t1, t2;

int main() {
	scanf("%s", s);
	n = strlen(s);
	for (int i = 0; i < n; ++i) {
	  if (i + 1 < n && s[i] == s[i + 1]) {
		  num[i + 1] = 1;
		} else {
		  num[i + 1] = 0;
		}
	}
	for (int i = 1; i <= n; ++i) {
		num[i] += num[i - 1];
	}
	scanf("%d", &m);
	for (int i = 1; i <= m; ++i) {
	  scanf("%d %d", &t1, &t2);
	  printf("%d\n", num[t2 - 1] - num[t1 - 1]);
	}
	return 0;
}