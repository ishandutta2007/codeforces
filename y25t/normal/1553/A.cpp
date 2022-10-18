#include<bits/stdc++.h>

int T;

int n;

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		printf("%d\n",n/10+(n%10>=9));
	}
}