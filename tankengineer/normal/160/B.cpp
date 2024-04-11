#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n;
	char s[205];
	scanf("%d%s", &n, s);
	sort(s, s + n);
	sort(s + n, s + n * 2);
	bool ans1 = true, ans2 = true;
	for (int i = 0; i < n; ++i) {
		ans1 &= s[i] > s[i + n];
		ans2 &= s[i] < s[i + n];
	}
	puts(ans1 || ans2 ? "YES" : "NO");
	return 0;
}