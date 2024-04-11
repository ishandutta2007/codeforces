#include<stdio.h>
#pragma warning(disable:4996)
#define MN 200000
using namespace std;

int N,Q;
int p[MN];
int r[MN];

int par(int n){
	if(p[n]==n)return n;
	return p[n]=par(p[n]);
}

int rar(int n){
	if(r[n]==n)return n;
	return r[n]=rar(r[n]);
}

int main(){
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	scanf("%d%d",&N,&Q);
	for(int i=0;i<N;i++)p[i]=i,r[i]=i;
	while(Q--){
		int type,a,b;
		scanf("%d%d%d",&type,&a,&b),--a,--b;
		if(type==1){
			p[par(b)]=par(a);
		}
		else if(type==2){
			if(a==b)continue;
			for(int n=a;n<b;){
				if(r[n]==n){
					p[par(n+1)]=par(n);
					r[n]=n+1;
				}
				n=rar(n);
			}
		}
		else{
			puts(par(a)==par(b)?"YES":"NO");
		}
	}
	return 0;
}