#include"bits/stdc++.h"
using namespace std;
int n;
int main(){
	scanf("%d",&n);
	if(n<=998)printf("%d\n",n+2);
	else if(n==999)puts("1");
	else if(n==1000)puts("2");
	return 0;
}