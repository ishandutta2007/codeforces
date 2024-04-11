#include <bits/stdc++.h>
using namespace std;

int a,b,c,d;

int main() {
	scanf("%d%d%d%d",&a,&b,&c,&d);
	int n = c-a+1;
	int m = (d-b)/2+1;
	printf("%lld\n",1LL*n*m-n/2);

	return 0;
}