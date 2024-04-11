#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
	scanf("%d",&n);
	for (int i=1;i<=1000;i++) {
		string s = to_string(i);
		bool ok = 1;
		for (char c: s) if (c!='4' && c!='7') ok = 0;
		if (ok && n%i==0) return printf("YES\n"), 0;
	}
	printf("NO\n");

	return 0;
}