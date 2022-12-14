//*

#include<stdio.h>
#include<algorithm>
//#pragma warning(disable:4996)
#define MN 100

int N,ans,pen;
int A[MN];

int main(){
	int i,s=0;
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	scanf("%d",&N);
	for(i=0;i<N;i++)scanf("%d",&A[i]);
	std::sort(A,A+N);
	for(i=0;i<N;i++){
		s+=A[i];
		if(s>710)break;
		if(s>350)pen+=s-350;
	}
	printf("%d %d",i,pen);
	return 0;
}

//*/