#include <bits/stdc++.h>
using namespace std;

int a, b, c, d;

int main(){
	scanf("%d%d%d%d",&a,&b,&c,&d);
	int a1 = 2*a;
	int b1 = 2*b;
	int c1 = min(2*c,2*d);
	if(a1 > 2*d && b1 > 2*d && c1 >= c && c1 >= d && c1 <= 2*c && c1 <= 2*d)
		printf("%d\n%d\n%d\n",a1,b1,c1);
	else printf("-1\n");
	return 0;
}