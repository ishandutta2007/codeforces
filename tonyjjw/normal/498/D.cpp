//*
#include<stdio.h>
#pragma warning(disable:4996)
#define MN 100000
#define TN 131072
#define PN 60

int N,Q,now;
int A[MN];
int T[2*TN][PN];
char inp[5];

void set(int n,int L,int R){
	int i;
	if(L==R){
		for(i=0;i<PN;i++){
			T[n][i]=(i%A[L])?1:2;
		}
		return;
	}
	int M=(L+R)>>1;
	set(2*n,L,M);
	set(2*n+1,M+1,R);
	for(i=0;i<PN;i++){
		T[n][i]=(i%A[L])?T[2*n][i]:(T[2*n][(i+1)%PN]+1);
		T[n][i]+=((i+T[n][i])%A[M+1])?T[2*n+1][(i+T[n][i])%PN]:(T[2*n+1][(i+T[n][i]+1)%PN]+1);
	}
}
void u(int n,int L,int R,int p){
	if(R<p || p<L)return ;
	int i;
	if(L==R){
		for(i=0;i<PN;i++){
			T[n][i]=(i%A[L])?1:2;
		}
		return;
	}
	int M=(L+R)>>1;
	u(2*n,L,M,p);
	u(2*n+1,M+1,R,p);
	for(i=0;i<PN;i++){
		T[n][i]=(i%A[L])?T[2*n][i]:(T[2*n][(i+1)%PN]+1);
		T[n][i]+=((i+T[n][i])%A[M+1])?T[2*n+1][(i+T[n][i])%PN]:(T[2*n+1][(i+T[n][i]+1)%PN]+1);
	}
}
void c(int n,int L,int R,int l,int r){
	if(R<l || r<L)return;
	int i;
	int M=(L+R)>>1;
	if(l<=L && R<=r){
		now+=T[n][now%PN];
		return;
	}
	c(2*n,L,M,l,r);
	c(2*n+1,M+1,R,l,r);
}

int main(){
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	int i,j,a,b;
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%d",&A[i]);
	}
	set(1,0,N-1);
	scanf("%d",&Q);
	for(i=0;i<Q;i++){
		scanf("%s",inp);
		if(*inp=='C'){
			scanf("%d%d",&a,&b),--a;
			A[a]=b;
			u(1,0,N-1,a);
		}
		else{
			scanf("%d%d",&a,&b),--a,b-=2;
			now=0;
			c(1,0,N-1,a,b);
			printf("%d\n",now);
		}
	}
	return 0;
}
//*/