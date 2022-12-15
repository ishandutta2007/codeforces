#include <bits/stdc++.h>
using namespace std;

double p1, p2;
int a, b, c, d;

int main(){
	scanf("%d%d%d%d",&a,&b,&c,&d);
	p1=max(3/10.0*a,a-a/250.0*c);
	p2=max(3/10.0*b,b-b/250.0*d);
	if(abs(p1-p2)<=1e-6) printf("Tie\n");
	else if(p1>p2) printf("Misha\n");
	else printf("Vasya\n");
	return 0;
}