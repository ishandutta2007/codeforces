#include<cstdio>

int T;

int main(){
	scanf("%d",&T);
	while(T--){
		int l,r;
		scanf("%d%d",&l,&r);
		if(r>=(l<<1))
			printf("%d %d\n",l,l<<1);
		else
			puts("-1 -1");
	}
}