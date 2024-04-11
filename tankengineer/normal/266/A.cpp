#include<cstdio>
#include<iostream>
#include<cstring>
#include<iostream>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	char ch[55];
	scanf("%s", ch);
	int ans = 0;
	for (int i = 1; i < n; ++i) {
		ans += ch[i] == ch[i - 1];
	}
	printf("%d\n", ans);
	return 0;
}