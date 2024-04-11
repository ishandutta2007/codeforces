#include <bits/stdc++.h>

using namespace std;

int a,b;

int main() {
	scanf("%d%d",&a,&b);
	if (a>b) swap(a,b);
	printf("%d %d\n",a,(b-a)/2);

    return 0;
}