#include<stdio.h>
int main(){
	int r,g,b,t;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&r,&g,&b);
		if(r>g+b+1||g>r+b+1||b>r+g+1)
			puts("No");
		else
			puts("Yes");
	}
}