#include<cstdio>

int a,b,c;

int main(){
	scanf("%d%d%d",&a,&b,&c);
	if(a>b+c)
		printf("+");
	else if(b>a+c)
		printf("-");
	else if(a==b&&!c)
		printf("0");
	else
		printf("?"); 
}