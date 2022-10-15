#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		int l,r;
		int time=0;
		scanf("%d",&n);
		for (int i=0;i<n;++i){
			scanf("%d%d",&l,&r);
			if(time>r){
				printf("0 ");
				continue;
			} 
			time=max(l,time);
			printf("%d ",time);
			time++;
		}
		printf("\n");
	}
}