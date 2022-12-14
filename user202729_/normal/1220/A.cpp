#include<cstdio>

int main(){
	int n0=0,n1=0;
	while(true){
		int x=std::getchar();
		if(x==EOF)break;
		n0+=x=='z';
		n1+=x=='n';
	}
	while(n1--)std::printf("1 ");
	while(n0--)std::printf("0 ");
	std::printf("\n");
}