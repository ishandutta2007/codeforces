#include <bits/stdc++.h>
using namespace std;

int n;
vector<char> sign;

int main() {
	int pos = 1;
	int neg = 0;
	scanf(" %*c");
	sign.push_back('+');
	while (true) {
		char c;
		scanf(" %c",&c);
		if (c=='=') break;
		if (c=='+') pos+=1;
		if (c=='-') neg+=1;
		sign.push_back(c);
		scanf(" %*c");
	}
	scanf("%d",&n);
	int high = pos*n-neg*1;
	int low = pos*1-neg*n;
	if (n<low || high<n) return printf("Impossible\n"), 0;
	printf("Possible\n");
	int ext = high-n;
	bool first = 1;
	for (char c: sign) {
		if (!first) printf("%c ",c);
		if (c=='+') printf("%d ",max(1,n-ext));
		else printf("%d ",min(n,1+ext));
		ext = max(0,ext-n+1);
		first = 0;
	}
	printf("= %d\n",n);

	return 0;
}