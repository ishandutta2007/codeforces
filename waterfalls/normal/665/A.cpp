#include <bits/stdc++.h>
using namespace std;

int ta,b,tb;

int main() {
	int h,m;
	scanf("%*d%d%d%d%d:%d",&ta,&b,&tb,&h,&m);
	int low = h*60+m;
	int high = low+ta;
	int ans = 0;
	for (int i=5*60;i<=23*60+59;i+=b) {
		if (low<i+tb && i<high) ans+=1;
	}
	printf("%d\n",ans);

	return 0;
}