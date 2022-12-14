//*
#include<stdio.h>
#pragma warning(disable:4996)
#define MN 300

int N,sx,sy,ex,ey,ans;
long long A,B,C;

int main(){
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	int i;
	scanf("%d%d",&sx,&sy);
	scanf("%d%d",&ex,&ey);
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%lld%lld%lld",&A,&B,&C);
		long long v1=A*sx+B*sy+C;
		long long v2=A*ex+B*ey+C;
		if((v1<0 && v2>0) || (v1>0 && v2<0))ans++;
	}
	printf("%d",ans);
	return 0;
}
//*/