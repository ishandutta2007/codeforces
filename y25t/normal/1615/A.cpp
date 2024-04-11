#include<bits/stdc++.h>

int T;

int main(){
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		int s=0;
		for(int i=1;i<=n;i++){
			int x;
			scanf("%d",&x);
			s+=x;
		}
		printf("%d\n",s%n==0?0:1);
	}
}