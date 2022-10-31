#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d",&n);
	printf("%d %d\n",n/7*2+max(0,n%7-5), n/7*2+min(2,n%7));
	return 0;
}