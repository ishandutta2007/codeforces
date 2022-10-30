#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
	scanf("%d",&n);
	char prev = 'A';
	int ans = 0;
	for (int i=0;i<n;i++) {
		char c;
		scanf(" %c",&c);
		if (c==prev) ans+=1;
		prev = c;
	}
	printf("%d\n",ans);

	return 0;
}