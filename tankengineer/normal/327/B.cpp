#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAX = 10000000;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
	  printf("%d%c", MAX - n + i, i == n ? '\n' : ' ');
	}
	return 0;
}