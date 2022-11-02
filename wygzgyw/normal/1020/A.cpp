#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int k,n,h,a,b;
int f(int x) {
	if (a<=x&&x<=b) return x;
	if (a>x) return a;
	return b;
}
int main() {
//	freopen("1.txt","r",stdin);
	scanf("%d %d %d %d %d",&n,&h,&a,&b,&k);
	int x1,y1,x2,y2;
	while (k--) {
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		if (x1==x2) printf("%d\n",abs(y1-y2));
		else
			printf("%d\n",abs(f(y1)-f(y2))+abs(y1-f(y1))+abs(y2-f(y2))+abs(x2-x1));
	}
	return 0;
}