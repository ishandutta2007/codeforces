#include<bits/stdc++.h>

int T;

int c,d;

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&c,&d);
		if(!c&&!d)
			puts("0");
		else if(c==d)
			puts("1");
		else if(!((c+d)&1))
			puts("2");
		else
			puts("-1");
	}
}