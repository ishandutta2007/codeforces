#include<bits/stdc++.h>
using namespace std;
int main() {
	int tests;
	scanf("%d", &tests);
	for(int qq = 1; qq <= tests; qq++) {
		string a, b, c;
		cin >> a >> b >> c;
		int n = a.size();
		bool flag = true;
		for(int i = 0; i < n; i++) {
			if((a[i] == c[i]) || b[i] == c[i]) {
			}else flag = false;
		}
		printf("%s\n", flag ? "YES\n" : "NO\n");
	}
}