#include <bits/stdc++.h>
using namespace std;

int n, p, l, r;

int main(){
	scanf("%d%d%d%d",&n,&p,&l,&r);
	if(l!=1&&r!=n){
		int x = min(abs(r-p),abs(p-l));
		printf("%d\n",x+2+abs(r-l));
	}
	else if(r!=n){
		printf("%d\n",abs(r-p)+1);
	}
	else if(l!=1){
		printf("%d\n",abs(l-p)+1);
	}
	else printf("0\n");
	return 0;
}