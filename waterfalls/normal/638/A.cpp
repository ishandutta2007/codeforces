#include <bits/stdc++.h>
using namespace std;

int n,a;

int main() {
	scanf("%d%d",&n,&a);
	if (a%2) printf("%d\n",a/2+1);
	else printf("%d\n",(n-a)/2+1);

	return 0;
}