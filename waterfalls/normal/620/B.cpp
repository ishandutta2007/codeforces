#include <bits/stdc++.h>
using namespace std;

int has[10] = {6,2,5,5,4,5,6,3,7,6};
int a,b;

int main() {
	scanf("%d%d",&a,&b);
	int ans = 0;
	for (int i=a;i<=b;i++) {
		int s = i;
		while (s) ans+=has[s%10], s/=10;
	}
	printf("%d\n",ans);

	return 0;
}