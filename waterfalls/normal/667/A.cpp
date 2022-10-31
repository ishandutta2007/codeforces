#include <bits/stdc++.h>
using namespace std;

const double PI = 2*acos(0.0);

int d,h,v,e;

int main() {
	scanf("%d%d%d%d",&d,&h,&v,&e);
	if (PI*d*d/4*e>v) printf("NO\n");
	else printf("YES\n%1.9f\n",PI*d*d/4*h/(v-PI*d*d/4*e));

	return 0;
}