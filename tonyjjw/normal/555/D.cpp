//*
#include<stdio.h>
#include<algorithm>
#pragma warning(disable:4996)
#define MN 200000
using namespace std;

int N,M;
int x[MN];
int rev[MN];
int pos[MN];

bool cmp(int a,int b){
	return x[a]<x[b];
}

int main(){
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++){
		scanf("%d",&x[i]);
		rev[i]=i;
	}
	sort(rev,rev+N,cmp);
	for(int i=0;i<N;i++){
		pos[rev[i]]=i;
	}
	sort(x,x+N);
	for(int i=0;i<M;i++){
		int a,len;
		scanf("%d%d",&a,&len),--a;
		a=pos[a];
		int past=-1,pastlen;

		for(;;){
			//go right
			if(past==a){
				if(pastlen==len){
					printf("%d\n",rev[a]+1);
					break;
				}
				len=len%(pastlen-len);
			}
			if(len==0){
				printf("%d\n",rev[a]+1);
				break;
			}
			int l,m,r;
			int p;
			for(l=0,r=N-1;l<=r;){
				m=(l+r)>>1;
				if(x[m]<=x[a]+len){
					p=m;
					l=m+1;
				}
				else{
					r=m-1;
				}
			}
			past=a;
			pastlen=len;
			len-=x[p]-x[a];
			a=p;

			//go left
			if(len==0){
				printf("%d\n",rev[a]+1);
				break;
			}
			for(l=0,r=N-1;l<=r;){
				m=(l+r)>>1;
				if(x[m]>=x[a]-len){
					p=m;
					r=m-1;
				}
				else{
					l=m+1;
				}
			}
			len-=x[a]-x[p];
			a=p;
		}
	}
	return 0;
}
//*/