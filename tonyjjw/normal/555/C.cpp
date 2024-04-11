//*
#include<stdio.h>
#include<algorithm>
#include<set>
#pragma warning(disable:4996)
#define TN 262144
using namespace std;

int N,Q;
char op[3];
set<int> S;

struct NODE{
	int val,l,r;
}node[3*6400000];

int nodecnt;

int newnode(){
	node[nodecnt].l=node[nodecnt].r=-1;
	return nodecnt++;
}

int get(int n,int L,int R,int p){
	if(p<L || p>R)return 0;
	if(L==p && R==p)return node[n].val;
	int M=(L+R)>>1;
	if(p<=M){
		if(node[n].l==-1){
			node[n].l=newnode();
		}
		return max(node[n].val,get(node[n].l,L,M,p));
	}
	else{
		if(node[n].r==-1){
			node[n].r=newnode();
		}
		return max(node[n].val,get(node[n].r,M+1,R,p));
	}
}

void update(int n,int L,int R,int l,int r,int v){
	if(R<l || L>r)return;
	if(l<=L && R<=r){
		node[n].val=max(node[n].val,v);
		return;
	}
	int M=(L+R)>>1;
	if(M>=l){
		if(node[n].l==-1){
			node[n].l=newnode();
		}
		update(node[n].l,L,M,l,r,v);
	}
	if(M+1<=r){
		if(node[n].r==-1){
			node[n].r=newnode();
		}
		update(node[n].r,M+1,R,l,r,v);
	}
}

int main(){
	newnode();newnode();
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	scanf("%d%d",&N,&Q);
	for(int i=0;i<Q;i++){
		int x,y;
		scanf("%d%d%s",&x,&y,op);
		if(S.find(x)!=S.end()){
			puts("0");
			continue;
		}
		S.insert(x);
		if(*op=='U'){
			int v=get(0,1,N,x);
			printf("%d\n",y-v);
			update(1,1,N,v+1,y,x);
		}
		else{
			int v=get(1,1,N,y);
			printf("%d\n",x-v);
			update(0,1,N,v+1,x,y);
		}
	}
	return 0;
}
//*/