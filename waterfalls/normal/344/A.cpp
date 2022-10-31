#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
	scanf("%d",&n);
	char p = ' ';
	int ans = 0;
	for (int i=0;i<n;i++) {
        char n;
        scanf(" %*c%c",&n);
        if (n!=p) ans+=1;
        p = n;
	}
	printf("%d\n",ans);

	return 0;
}