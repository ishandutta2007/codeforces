#include<bits/stdc++.h>

int T;

int main(){
	scanf("%d",&T);
	while(T--){
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		printf("%d\n",(b>a)+(c>a)+(d>a));
	}
}