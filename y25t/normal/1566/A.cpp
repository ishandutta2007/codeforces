#include<bits/stdc++.h>

int T;

int main(){
	scanf("%d",&T);
	while(T--){
		int n,s;
		scanf("%d%d",&n,&s);
		printf("%d\n",s/(n-(n+1)/2+1));
	}
}