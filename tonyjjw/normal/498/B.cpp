//*
#include<stdio.h>
#pragma warning(disable:4996)
#define MN 5010

int N,T;
double p[MN],D[MN][MN+1];
int t[MN];

double mpow(double a,int n){
	double v=1;
	while(n){
		if(n&1)v*=a;
		n>>=1;
		a=a*a;
	}
	return v;
}

int main(){
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	int i,j,a;
	scanf("%d%d",&N,&T);
	for(i=0;i<N;i++){
		scanf("%d%d",&a,&t[i]);
		p[i]=(double)a/100;
	}
	for(j=1;j<=T;j++){
		if(j>=t[i])D[N-1][j]=1;
		else{
			D[N-1][j]=p[N-1]+(1-p[N-1])*D[N-1][j-1];
		}
	}
	for(i=N-1;i>=0;i--){
		for(j=1;j<=T;j++){
			if(j-t[i]-1>=0){
				D[i][j]=p[i]*(D[i+1][j-1]+1)+(1-p[i])*D[i][j-1]-mpow(1-p[i],t[i])*(D[i+1][j-t[i]-1]-D[i+1][j-t[i]]);
			}
			else if(j-t[i]>=0){
				D[i][j]=p[i]*(D[i+1][j-1]+1)+(1-p[i])*D[i][j-1]+mpow(1-p[i],t[i])*(D[i+1][j-t[i]]+1);
			}
			else{
				D[i][j]=p[i]*(D[i+1][j-1]+1)+(1-p[i])*D[i][j-1];
			}
		}
	}
	printf("%lf",D[0][T]);
	return 0;
}
//*/