//*

#include<stdio.h>
#include<map>
#pragma warning(disable:4996)
#define MN 100000
using namespace std;

map<int,int> M;

int N,A[MN],a,b,p[MN+2];

int par(int n){
	return p[n]==n?n:p[n]=par(p[n]);
}

int main(){
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	scanf("%d%d%d",&N,&a,&b);
	int i;
	for(i=0;i<N+2;i++)p[i]=i;
	for(i=0;i<N;i++)scanf("%d",&A[i]),M[A[i]]=i;
	for(i=0;i<N;i++){
		if(M.find(a-A[i])!=M.end()){
			int p1=par(i),p2=par(M[a-A[i]]);
			p[p2]=p1;
		}
		else{
			int p1=par(i),p2=par(N+1);
			p[p2]=p1;
		}
		if(M.find(b-A[i])!=M.end()){
			int p1=par(i),p2=par(M[b-A[i]]);
			p[p2]=p1;
		}
		else{
			int p1=par(i),p2=par(N);
			p[p2]=p1;
		}
	}
	if(par(N)==par(N+1)){
		puts("NO");
		return 0;
	}
	puts("YES");
	for(i=0;i<N;i++){
		printf("%d ",par(i)==par(N)?0:1);
	}
	return 0;
}

//*/