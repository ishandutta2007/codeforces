#include<stdio.h>

int check[1000000];
int N,K;
int A[100000];

int main(){
	int i,C;
	scanf("%d%d",&N,&K);
	if(N==1){
		if(K==0){
			puts("1");
			return 0;
		}
		else{
			puts("-1");
			return 0;
		}
	}
	A[0]=K-(N-2)/2;
	if(A[0]<=0){
		puts("-1");
		return 0;
	}
	A[1]=2*A[0];
	if(A[0]<1000000)check[A[0]]=1;
	if(A[1]<1000000)check[A[1]]=1;
	C=1;
	for(i=2;i+1<N;i+=2){
		while(check[C] || check[C+1])C++;
		A[i]=C;
		A[i+1]=C+1;
		C+=2;
	}
	if(N&1){
		while(check[C])C++;
		A[N-1]=C;
	}
	for(i=0;i<N;i++)printf("%d ",A[i]);
	return 0;
}