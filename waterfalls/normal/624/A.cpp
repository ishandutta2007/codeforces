#include <bits/stdc++.h>
using namespace std;

int d,L,v1,v2;

int main() {
	scanf("%d%d%d%d",&d,&L,&v1,&v2);
	printf("%1.9f\n",1.*(L-d)/(v1+v2));

	return 0;
}