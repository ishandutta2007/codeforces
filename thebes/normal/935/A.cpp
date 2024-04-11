#include <bits/stdc++.h>
using namespace std;

int n, cnt, i;

int main(){
	scanf("%d",&n);
	for(i=1;i<n;i++){
		if(n%i==0) cnt++;
	}
	printf("%d\n",cnt); 
	return 0;
}