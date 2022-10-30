#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	char s[1005];
	scanf("%s", s);
	if (s[0] >= 'a') s[0] = s[0] - 'a' + 'A';
	printf("%s\n", s);
	return 0;
}