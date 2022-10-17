#include<stdio.h>
int T,l,r;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&l,&r);
		if(l*2>r)
			printf("%d\n",r-l);
		else printf("%d\n",r-r/2-1);
	}
	return 0;
}