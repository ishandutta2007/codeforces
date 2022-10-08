#include"bits/stdc++.h"
using namespace std;
int n,k; 
int main(){
	scanf("%d%d",&n,&k);int i;
	for (i=1; i<=n&&k<=240; i++) {
		k+=5*i;
		if (k>240) break;
	}
	printf ("%d\n",i-1);
	return 0;
}