#include<stdio.h>

int Q,N,V[100];

struct INTERVAL{
	int s,t;
}A[100];

void dfs(int n){
	int i;
	V[n]=1;
	for(i=0;i<N;i++){
		if(((A[i].s<A[n].s && A[n].s<A[i].t) || (A[i].s<A[n].t && A[n].t<A[i].t)) && !V[i]){
			dfs(i);
		}
	}
}

int main(){
	scanf("%d",&Q);
	int i,j,a,b,c;
	for(i=0;i<Q;i++){
		scanf("%d%d%d",&c,&a,&b);
		if(c==1){
			A[N].s=a,A[N].t=b,N++;
		}
		else{
			--a,--b;
			for(j=0;j<N;j++)V[j]=0;
			dfs(a);
			if(V[b]){
				puts("YES");
			}
			else{
				puts("NO");
			}
		}
	}
	return 0;
}