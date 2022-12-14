#include<stdio.h>
#pragma warning(disable:4996)

int M,N;
double ans,v1,v2;

double pow(double a,int b){
	double v=1;
	while(b){
		if(b&1)v*=a;
		a=a*a;
		b>>=1;
	}
	return v;
}

int main(){
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	int i;
	scanf("%d%d",&M,&N);
	for(i=1;i<=M;i++){
		v1=v2,v2=pow((double)i/M,N);
		ans+=i*(v2-v1);
	}
	printf("%lf",ans);
	return 0;
}