#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

char ans[] = "1001010111001010";

int main() {
	int n;
	scanf("%d", &n);
	printf("%c\n", ans[--n]);
	return 0;
}