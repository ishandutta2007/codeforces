#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

char s[1000005];
int l, ans[1000005], head, tail;

int main() {
	scanf("%s", s);
	l = strlen(s);
	head = 1; tail = l;
	for (int i = 1; i <= l; ++i) {
	  if (s[i - 1] == 'l') {
	    ans[tail--] = i;
		} else {
			ans[head++] = i;
	  }
	}
	for (int i = 1; i <= l; ++i) {
	  printf("%d\n", ans[i]);
	}
	return 0;
}