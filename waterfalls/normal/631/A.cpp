#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
	scanf("%d",&n);
	int a = 0;
	for (int i=0;i<n;i++) {
		int x;
		scanf("%d",&x);
		a|=x;
	}
	int b = 0;
	for (int i=0;i<n;i++) {
		int x;
		scanf("%d",&x);
		b|=x;
	}
	printf("%d\n",a+b);

    return 0;
}