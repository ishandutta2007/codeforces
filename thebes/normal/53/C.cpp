#include <bits/stdc++.h>
using namespace std;

int n, i;

int main(){
	scanf("%d",&n);
	for(i=1;i<=ceil(n/2.0);i++){
		printf("%d ",i);
		if(i==ceil(n/2.0)&&n&1)
			break;
		printf("%d ",n-i+1);
	}
	return 0;
}