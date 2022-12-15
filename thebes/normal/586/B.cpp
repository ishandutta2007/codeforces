#include <bits/stdc++.h>
using namespace std;

int n, e[51], p[51], c[51], i, a=1<<30, b=1<<30;

int main(){
	for(scanf("%d",&n),i=1;i<n;i++)
		scanf("%d",&e[i]),e[i]+=e[i-1];
	for(i=1;i<n;i++)
		scanf("%d",&p[i]),p[i]+=p[i-1];
	for(i=0;i<n;i++)
		scanf("%d",&c[i]);
	for(i=0;i<n;i++){
		int t = e[i]+(p[n-1]-p[i])+c[i];
		if(t < a){ b = a; a = t;}
		else if(t < b) b = t;
	}
	printf("%d\n",a+b);
	return 0;
}