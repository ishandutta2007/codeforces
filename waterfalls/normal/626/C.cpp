#include <bits/stdc++.h>
using namespace std;

int n,m;

int main() {
	scanf("%d%d",&n,&m);
	for (int i=1;i<=10000000;i++) {
		int two = i/2;
		int three = i/3;
		int six = i/6;
		two-=six;
		three-=six;
		if (max(0,n-two)+max(0,m-three)<=six) return printf("%d\n",i), 0;
	}

	return 0;
}