#include <bits/stdc++.h>
using namespace std;

int n,a,b;

int main() {
	scanf("%d%d%d",&n,&a,&b);
	printf("%d\n",(a-1+b%n+n)%n+1);

	return 0;
}