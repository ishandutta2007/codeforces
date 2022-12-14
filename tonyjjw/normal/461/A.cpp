//*
#include<stdio.h>
#include<algorithm>
//#pragma warning(disable:4996)

int N;
int A[300000];
long long ans;

int main(){
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	int i;
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%d",&A[i]);
	}
	std::sort(A,A+N);
	for(i=0;i<N;i++){
		ans+=(long long)(i+2)*A[i];
	}
	ans-=A[N-1];
	printf("%lld",ans);
	return 0;
}

//*/