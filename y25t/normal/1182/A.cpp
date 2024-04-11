#include<cstdio>

int n;

int main(){
	scanf("%d",&n);
	if(n%2)
		printf("0");
	else{
		int tmp=1;
		for(int i=1;i<=(n>>1);i++)
			tmp*=2;
		printf("%d",tmp);
	}
}