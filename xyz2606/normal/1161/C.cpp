#include<bits/stdc++.h>
using namespace std;
int a[66];
int main() {
	int n;
	scanf("%d", &n);
	int mn = 51;
	for(int i(1); i <= n; i++) {
		scanf("%d", &a[i]);
		mn = min(mn, a[i]);
	}
	int cnt = 0;
	for(int i(1); i <= n; i++) cnt += a[i] != mn;
	printf("%s\n", cnt < n / 2 ? "Bob" : "Alice");
}