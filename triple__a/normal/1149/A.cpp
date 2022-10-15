#include<bits/stdc++.h>
using namespace std;

int n,a,b;

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		int u;
		scanf("%d",&u);
		if (u==1) a++;
		else b++;
	}
	if (b){
		if (a){
			printf("2 1 ");
			for (int i=1;i<b;++i){
				printf("2 ");
			}
			for (int i=1;i<a;++i){
				printf("1 ");
			}
		}
		else{
			for (int i=1;i<=b;++i){
				printf("2 ");
			}
		}
	}
	else{
		for (int i=1;i<=a;++i){
			printf("1 ");
		}
	}
	return 0;
}