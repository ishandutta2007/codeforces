#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	while (t--){
		int u,v;
		scanf("%d%d",&u,&v);
		if (__gcd(u,v)==1){
			printf("Finite\n");
		}
		else{
			printf("Infinite\n");
		}
	}
	return 0;
}