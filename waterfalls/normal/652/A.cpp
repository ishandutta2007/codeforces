#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int h2,a,b;
ll h1;

int main() {
	scanf("%lld%d%d%d",&h1,&h2,&a,&b);
	int day = 0;
	int hour = 14;
	for (int i=0;i<1e7;i++) {
		if (10<=hour && hour<22) h1+=a;
		else h1-=b;
		if (h1>=h2) return printf("%d\n",day), 0;
		hour+=1;
		if (hour==24) {
			hour = 0;
			day+=1;
		}
	}
	printf("-1\n");

	return 0;
}