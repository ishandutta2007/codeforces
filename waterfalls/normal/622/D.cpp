#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
	scanf("%d",&n);
	for (int i=n%2+1;i<n;i+=2) printf("%d ",i);
	for (int i=n-1;i>n%2;i-=2) printf("%d ",i);
	for (int i=(n+1)%2+1;i<=n;i+=2) printf("%d ",i);
	for (int i=n-2;i>=(n+1)%2;i-=2) printf("%d ",i);
	printf("%d\n",n);

	return 0;
}