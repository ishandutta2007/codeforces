#include <cstdio>

int n,m,cur;

int main(){
	scanf("%d%d",&n,&m); cur=m;
	for (int i=1,x;i<=n;i++){
		scanf("%d",&x);
		if (x<cur) cur-=x,printf("0 ");
		else{
			x-=cur;
			cur=m-x%m;
			printf("%d ",x/m+1);
		}
	}
	return 0;
}