#include <bits/stdc++.h>
using namespace std;

int n, i;

int main(){
	scanf("%d",&n);
	if(n%2) printf("-1\n");
	else{
		for(i=1;i<=n/2;i++)
			printf("%d %d ",2*i,2*i-1);
	}
	return 0;
}