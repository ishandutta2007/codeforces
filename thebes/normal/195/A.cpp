#include <bits/stdc++.h>
using namespace std;

int a, b, c, d, i;

int main(){
	scanf("%d%d%d",&a,&b,&c);
	d = a*c;
	while((i+c)*b<d) i++;
	printf("%d\n",i);
	return 0;
}