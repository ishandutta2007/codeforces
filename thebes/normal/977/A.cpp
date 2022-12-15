#include <bits/stdc++.h>
using namespace std;

int n, k;

int main(){
	scanf("%d%d",&n,&k);
	while(k--){
		if(n%10) n--;
		else n/=10;
	}
	printf("%d\n",n);
	return 0;
}