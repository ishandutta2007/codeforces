#include"bits/stdc++.h"
using namespace std;

int main(){
	int n,i;scanf("%d",&n);
	for(i=0;i+2<n;i+=2)
		printf("I hate that I love that ");
	if(n%2)puts("I hate it");
	else puts("I hate that I love it");
	return 0;
}