#include<stdio.h>

int N,A[1000000];
__int64 X,Y,S;

int main()
{
	int i;
	scanf("%d%I64d%I64d",&N,&X,&Y);
	if(N>Y){
		puts("-1");
		return 0;
	}
	for(i=0;i<N;i++){
		if(!i)A[i]=Y-(N-1);
		else	A[i]=1;
		
		S+=(__int64)A[i]*A[i];
	}
	if(S<X)puts("-1");
	else{
		for(i=0;i<N;i++){
			printf("%d\n",A[i]);
		}
	}
	return 0;
}