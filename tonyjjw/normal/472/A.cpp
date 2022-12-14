//*

#include<stdio.h>
#pragma warning(disable:4996)

int N;

int main(){
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	scanf("%d",&N);
	if(N&1){
		printf("%d %d",9,N-9);
	}
	else{
		printf("%d %d",4,N-4);
	}
	return 0;
}

//*/