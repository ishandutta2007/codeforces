#include <bits/stdc++.h>
using namespace std;

int a,b;

int main() {
	scanf("%d%d",&a,&b);
	int ans = 0;
	while (a>0 && b>0) {
		if (a>b) swap(a,b);
		if (b<=1) break;
		ans+=1;
		a+=1;
		b-=2;
	}
	printf("%d\n",ans);

	return 0;
}