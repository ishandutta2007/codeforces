#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
	scanf("%d",&n);
	int num = 0;
	for (int i=0;i<n;i++) {
		int x;
		scanf("%d",&x);
		num+=x;
	}
	if (num!=n-(n!=1)) printf("NO\n");
	else printf("YES\n");

	return 0;
}