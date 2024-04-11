#include <bits/stdc++.h>
using namespace std;

int a,b,c;

int main() {
	scanf("%d%d%d",&a,&b,&c);
	double disc = sqrt(b*b-4*a*c);
	double one = (-b-disc)/2/a;
	double two = (-b+disc)/2/a;
	printf("%1.12f\n",max(one,two));
	printf("%1.12f\n",min(one,two));

	return 0;
}