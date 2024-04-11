#include <bits/stdc++.h>
using namespace std;

int a,b,c,d;

int main() {
	scanf("%d%d%d%d",&a,&b,&c,&d);
	printf("%d\n",max(abs(a-c),abs(b-d)));

	return 0;
}